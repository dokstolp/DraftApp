#!/usr/bin/python
import sys
import logging
logging.basicConfig(stream=sys.stderr)
sys.stdout = sys.stderr
sys.path.insert(0,"/var/www/DraftApp/")

print "in start"

#from app import app
from app import app as application
