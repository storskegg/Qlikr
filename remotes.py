import persistent

class Remote(persistent.Persistent):

    def __init__(self):
        self.count = 0
        self.hmac = ''
        self.hotp = ''
        self.enabled = False
        self.revoked = False

    def