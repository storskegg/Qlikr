import base64
import dbm
import hmac
import hashlib
import logging
import os
import persistent
import pyotp
import time

# ======================================================
# Set Up Env Shit
# from dotenv import load_dotenv
# load_dotenv()
#
# TOKEN_ID = os.getenv('QLIKR_TOKEN_ID')
# HMAC_SECRET = bytes(os.getenv('QLIKR_HMAC_SECRET'), 'utf-8')
# HOTP_SECRET = bytes(os.getenv('QLIKR_HOTP-SECRET'), 'utf-8')

# ======================================================
# Set Up Logging
logger = logging.getLogger("qlikr.{}".format('server'))
stderr_log_handler = logging.StreamHandler()
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
stderr_log_handler.setFormatter(formatter)
logger.addHandler(stderr_log_handler)
logger.setLevel('INFO')

__all__ = ['logger']

# ======================================================
# Set Up Data Store
class TokenStore(persistent.Persistent):
    def __init__(self):
        with dbm.open('token_store', 'c') as db:
            self.db = db

    def init_token(self, token):
        self.validate_token(token)
        self.assert_not_exists(token.id)
        self.db[token.id] = "True"
        self.db[self._key_hmac(token.id)] = token.hmac
        self.db[self._key_hotp(token.id)] = token.hotp
        self.db[self._key_count(token.id)] = '0'
        self.db[self._key_revoked(token.id)] = 'False'
        self.db[self._key_enabled(token.id)] = 'False'

    def revoke(self, token_id):
        self.assert_exists(token_id)
        self.db[self._key_revoked(token_id)] = 'True'
        self.db[self._key_enabled(token_id)] = 'False'

    def is_revoked(self, token_id):
        self.assert_exists(token_id)
        return self._get_revoked(token_id) == 'True'

    def is_enabled(self, token_id):
        self.assert_exists(token_id)
        return self._get_enabled(token_id) == 'True'

    def assert_exists(self, token_id):
        assert token_id in self.db, "Token does not exist"

    def assert_not_exists(self, token_id):
        assert token_id not in self.db, "Token already exists"

    def validate_token(self, token):
        assert 'id' in token, "Expected id in token"
        assert 'hmac' in token, "Expected hmac in token"
        assert 'hotp' in token, "Expected hotp in token"

    def _get_enabled(self, token_id):
        return self.db[self._key_enabled(token_id)]

    def _get_revoked(self, token_id):
        return self.db[self._key_revoked(token_id)]

    def _set_enabled(self, token_id, value):
        if value:
            self.db[self._key_enabled(token_id)] = 'True'
        else:
            self.db[self._key_enabled(token_id)] = 'False'

    def _key_count(self, token_id):
        return "{}_count".format(token_id)

    def _key_hmac(self, token_id):
        return "{}_hmac".format(token_id)

    def _key_hotp(self, token_id):
        return "{}_hotp".format(token_id)

    def _key_enabled(self, token_id):
        return "{}_enabled".format(token_id)

    def _key_revoked(self, token_id):
        return "{}_revoked".format(token_id)


with TokenStore as db:
    logger.info("[DB] Instantiate db")


def init_count(token_id):
    db[token_id] = '0'


def reset_count(token_id):
    if token_id in db:
        init_count(token_id)


def get_count(token_id):
    return int(db[token_id])


def increment_count(token_id):
    if token_id in db:
        current_count = get_count(token_id)
        db[token_id] = "{}".format(current_count + 1)


def decrement_count(token_id):
    if token_id in db:
        current_count = get_count(token_id)
        db[token_id] = "{}".format(current_count - 1)


