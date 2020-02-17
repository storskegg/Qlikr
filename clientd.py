import daemon

from client import run_client, logger

with daemon.DaemonContext():
    logger.info('starting client as daemon')
    run_client()
