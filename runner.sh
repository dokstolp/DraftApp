#!/bin/bash
/home/pi/Desktop/pyFiles/dustypython/bin/python databuild.py
/home/pi/Desktop/pyFiles/dustypython/bin/python /home/pi/Desktop/NFL/tblmaker.py
sed "s/$/ `date`/" /home/pi/Desktop/NFL/timecron.txt > /home/pi/Desktop/NFL/timecron2.txt
mv /home/pi/Desktop/NFL/timecron2.txt /home/pi/Desktop/NFL/timecron.txt
