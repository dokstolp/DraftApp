import pymysql.cursors
import numpy as np
# Connect to the database
connection = pymysql.connect(host='',
                             user='',
                             password='',
                             db='NFL_Draft',
                             charset='utf8mb4',
			     local_infile=True,
                             cursorclass=pymysql.cursors.DictCursor)

try:
    with connection.cursor() as cursor:
	try:
		cursor.execute("DROP TABLE `qb_xls`")
		cursor.execute("DROP TABLE `rb_xls`")
		cursor.execute("DROP TABLE `wr_xls`")
		cursor.execute("DROP TABLE `te_xls`")
		cursor.execute("DROP TABLE `k_xls`")
		cursor.execute("DROP TABLE `de_xls`")
		cursor.execute("DROP TABLE `rank_xls`")
	except:
		print("table already doesn't exist")
	List = ['QB','RB','WR','TE','K','DE','RANK']
	plist = {'QB':'qb_xls','RB':'rb_xls','WR':'wr_xls','TE':'te_xls','K':'k_xls','DE':'de_xls'}
	pTable = {}
	Table = {}
	Load = {}
        Table['QB'] = "CREATE TABLE `qb_xls` (`player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL,`pattempts` FLOAT,`pattempts_high` FLOAT,`pattempts_low` float, `pcompletion` FLOAT,`pcompletion_high` FLOAT,`pcompletion_low` float, `pyards` varchar(255), `pyards_high` varchar(255), `pyards_low` varchar(255), `ptds` float, `ptds_high` float, `ptds_low` float, `pints` float, `pints_low` float, `pints_high` float, `rattempts` float, `rattempts_high` float, `rattempts_low` float, `ryards` float, `ryards_high` float, `ryards_low` float, `rtds` float, `rtds_high` float, `rtds_low` float, `fumbles` float, `fumbles_low` float, `fumbles_high` float, `fpoints` float, `fpoints_high` float, `fpoints_low` float, PRIMARY KEY(`player`)) ENGINE = memory;"
        Table['RB'] = "CREATE TABLE `rb_xls` (`player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL,`rattempts` FLOAT,`rattempts_high` FLOAT,`rattempts_low` float, `ryards` varchar(255), `ryards_high` varchar(255), `ryards_low` varchar(255), `rtds` float, `rtds_high` float, `rtds_low` float, `recattempts` float, `recattempts_high` float, `recattempts_low` float, `recyards` float, `recyards_high` float, `recyards_low` float, `rectds` float, `rectds_high` float, `rectds_low` float, `fumbles` float, `fumbles_low` float, `fumbles_high` float, `fpoints` float, `fpoints_high` float, `fpoints_low` float, PRIMARY KEY(`player`)) ENGINE = memory;"
        Table['WR'] = "CREATE TABLE `wr_xls` (`player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL,`rattempts` FLOAT,`rattempts_high` FLOAT,`rattempts_low` float, `ryards` varchar(255), `ryards_high` varchar(255), `ryards_low` varchar(255), `rtds` float, `rtds_high` float, `rtds_low` float, `recattempts` float, `recattempts_high` float, `recattempts_low` float, `recyards` varchar(255), `recyards_high` varchar(255), `recyards_low` varchar(255), `rectds` float, `rectds_high` float, `rectds_low` float, `fumbles` float, `fumbles_low` float, `fumbles_high` float, `fpoints` float, `fpoints_high` float, `fpoints_low` float, PRIMARY KEY(`player`)) ENGINE = memory;"
        Table['TE'] = "CREATE TABLE `te_xls` (`player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL, `recattempts` float, `recattempts_high` float, `recattempts_low` float, `recyards` varchar(255), `recyards_high` varchar(255), `recyards_low` varchar(255), `rectds` float, `rectds_high` float, `rectds_low` float, `fumbles` float, `fumbles_low` float, `fumbles_high` float, `fpoints` float, `fpoints_high` float, `fpoints_low` float, PRIMARY KEY(`player`)) ENGINE = memory;"
        Table['K'] = "CREATE TABLE `k_xls` (`player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL, `fg` FLOAT,`fg_high` FLOAT,`fg_low` float, `fga` float, `fga_high` float, `fga_low` float, `xpt` float, `xpt_high` float, `xpt_low` float, `fpts` float, `fpts_high` float, `fpts_low` float, PRIMARY KEY(`player`)) ENGINE = memory;"
        Table['DE'] = "CREATE TABLE `de_xls` (`rank` int, `player` varchar(255) NOT NULL, `team` varchar(255) NOT NULL,`bye_week` INT,`best_rank` int,`worst_rank` int, `average` float, `std_dev` float, `adps` int, PRIMARY KEY(`player`)) ENGINE = memory;"
	Table['RANK'] = "CREATE TABLE `rank_xls` (`rank` int, `player` varchar(255) NOT NULL,`position` varchar(255), `team` varchar(255) NOT NULL,`bye_week` INT,`best_rank` int,`worst_rank` int, `average` float, `std_dev` float, `adp` int, PRIMARY KEY(`rank`)) ENGINE = memory;"
	Load['QB'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/qb.xls' INTO TABLE qb_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['RB'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/rb.xls' INTO TABLE rb_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['WR'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/wr.xls' INTO TABLE wr_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['TE'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/te.xls' INTO TABLE te_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['K']  = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/k.xls' INTO TABLE k_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['DE'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/de.xls' INTO TABLE de_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"
	Load['RANK'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/rank.xls' INTO TABLE rank_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 6 LINES;"

	for tbl in List:
		cursor.execute(Table[tbl])
		cursor.execute(Load[tbl])
	
	myVals = "CREATE TABLE `myVals` (`name` varchar(255) NOT NULL, `value` float DEFAULT 3, `dpoints` float DEFAULT 0) ENGINE = memory;"
	myValsLoad = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/myVarBackup.txt' INTO TABLE myVals FIELDS TERMINATED BY ',' ENCLOSED BY '' LINES TERMINATED BY '\n';"
	myValsNew = "INSERT INTO myVals (name) SELECT player FROM rank_xls"

	#cursor.execute("DROP TABLE `myVals`")
	#cursor.execute(myVals)
	#cursor.execute(myValsLoad)
	#cursor.execute(myValsNew)
	for item in plist:
		cursor.execute("ALTER TABLE "+plist[item]+" ADD myadj float DEFAULT 3;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD mydp float DEFAULT 0;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD prorank float DEFAULT 230;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD adp float DEFAULT 230;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD position varchar(255) DEFAULT '"+item+"';")
		cursor.execute("UPDATE "+plist[item]+", myVals SET myadj = myVals.value WHERE "+plist[item]+".player = myVals.name")
		cursor.execute("UPDATE "+plist[item]+", myVals SET mydp = myVals.dpoints WHERE "+plist[item]+".player = myVals.name")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET prorank = rank_xls.average WHERE "+plist[item]+".player = rank_xls.player")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET "+plist[item]+".adp = rank_xls.adp WHERE "+plist[item]+".player = rank_xls.player")
		if plist[item] in "de_xls":
			continue
		cursor.execute("ALTER TABLE "+plist[item]+" ADD bye_week float DEFAULT 0;")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET "+plist[item]+".bye_week = rank_xls.bye_week WHERE "+plist[item]+".player = rank_xls.player")
	connection.commit()

finally:
    connection.close()
