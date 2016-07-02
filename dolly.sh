#!/bin/bash
#/usr/bin/wget "http://www.fantasypros.com/nfl/projections/qb.php?export=xls&min-yes=true&max-yes=true" -O /home/pi/Desktop/NFL/qb.xls
#/usr/bin/wget "http://www.fantasypros.com/nfl/projections/rb.php?export=xls&min-yes=true&max-yes=true" -O /home/pi/Desktop/NFL/rb.xls
#/usr/bin/wget "http://www.fantasypros.com/nfl/projections/wr.php?export=xls&min-yes=true&max-yes=true" -O /home/pi/Desktop/NFL/wr.xls
#/usr/bin/wget "http://www.fantasypros.com/nfl/projections/te.php?export=xls&min-yes=true&max-yes=true" -O /home/pi/Desktop/NFL/te.xls
#/usr/bin/wget "http://www.fantasypros.com/nfl/projections/k.php?export=xls&min-yes=true&max-yes=true" -O /home/pi/Desktop/NFL/k.xls
/usr/bin/wget "https://www.fantasypros.com/nfl/projections/qb.php?export=xls&week=draft&max-yes=true&min-yes=true&scoring=STD" -O /home/pi/Desktop/NFL/qb.xls
/usr/bin/wget "https://www.fantasypros.com/nfl/projections/rb.php?export=xls&week=draft&max-yes=true&min-yes=true&scoring=STD" -O /home/pi/Desktop/NFL/rb.xls
/usr/bin/wget "https://www.fantasypros.com/nfl/projections/wr.php?export=xls&week=draft&max-yes=true&min-yes=true&scoring=STD" -O /home/pi/Desktop/NFL/wr.xls
/usr/bin/wget "https://www.fantasypros.com/nfl/projections/te.php?export=xls&week=draft&max-yes=true&min-yes=true&scoring=STD" -O /home/pi/Desktop/NFL/te.xls
/usr/bin/wget "https://www.fantasypros.com/nfl/projections/k.php?export=xls&week=draft&max-yes=true&min-yes=true&scoring=STD" -O /home/pi/Desktop/NFL/k.xls
/usr/bin/wget "http://www.fantasypros.com/nfl/rankings/dst-cheatsheets.php?export=xls" -O /home/pi/Desktop/NFL/de.xls
/usr/bin/wget "http://www.fantasypros.com/nfl/rankings/consensus-cheatsheets.php?export=xls" -O /home/pi/Desktop/NFL/rank.xls
/usr/bin/wget "https://fantasyfootballcalculator.com/adp_csv.php?format=standard&teams=10" -O /home/pi/Desktop/NFL/adp.csv
