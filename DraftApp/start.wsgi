#!/usr/bin/python
import sys
import logging
logging.basicConfig(stream=sys.stderr)
sys.stdout = sys.stderr
name = "" #Put location here
sys.path.insert(0,"/var/www/"+name+"/")

from app import app as application
