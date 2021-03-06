import pymysql.cursors
import numpy as np
# Connect to the database
connection = pymysql.connect(host='localhost',
                             user='',
                             password='',
                             db='NFL_Draft',
                             charset='utf8mb4',
			     local_infile=True,
                             cursorclass=pymysql.cursors.DictCursor)

try:
    with connection.cursor() as cursor:
        # Create a new record
	cursor.execute("DROP TABLE `qb_xls`")
	cursor.execute("DROP TABLE `rb_xls`")
	cursor.execute("DROP TABLE `wr_xls`")
	cursor.execute("DROP TABLE `te_xls`")
	cursor.execute("DROP TABLE `k_xls`")
	cursor.execute("DROP TABLE `de_xls`")
	cursor.execute("DROP TABLE `rank_xls`")
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
        Table['DE'] = "CREATE TABLE `de_xls` (`space` varchar(255), `player` varchar(255) NOT NULL, `team` varchar(255), `bye_week` INT,`best_rank` int,`worst_rank` int, `average` float, `std_dev` float, `adps` int DEFAULT 32, PRIMARY KEY(`player`)) ENGINE = memory;"
	Table['RANK'] = "CREATE TABLE `rank_xls` (`rank` INT, `player` varchar(255) NOT NULL,`position` varchar(255), `team` varchar(255) NOT NULL,`bye_week` INT,`best_rank` int,`worst_rank` int, `average` float, `std_dev` float, `adp` int DEFAULT 316, PRIMARY KEY(`player`)) ENGINE = memory;"
	Load['QB'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/qb.xls' INTO TABLE qb_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['RB'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/rb.xls' INTO TABLE rb_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['WR'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/wr.xls' INTO TABLE wr_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['TE'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/te.xls' INTO TABLE te_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['K']  = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/k.xls' INTO TABLE k_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['DE'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/de.xls' INTO TABLE de_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"
	Load['RANK'] = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/data/rank.xls' INTO TABLE rank_xls FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n' IGNORE 5 LINES;"


	for tbl in List:
		cursor.execute(Table[tbl])
		cursor.execute(Load[tbl])
	
	myVals = "CREATE TABLE `myVals` (`rank` INT, `player` varchar(255) NOT NULL, `value` float DEFAULT 0, `dpoints` float DEFAULT 0, PRIMARY KEY(`player`)) ENGINE = memory;"
	myValsLoad = "LOAD DATA LOCAL INFILE '/home/pi/Desktop/NFL/myVarBackup.xls' INTO TABLE myVals FIELDS TERMINATED BY '\t' ENCLOSED BY '' LINES TERMINATED BY '\n';"
	myValsNew = "INSERT INTO myVals (player,rank) SELECT player,rank FROM rank_xls;"

#	cursor.execute("DROP TABLE `myVals`")
#	cursor.execute(myVals)
#	cursor.execute(myValsLoad)
#	cursor.execute(myValsNew)

#	userTable = "CREATE TABLE `users` (`username` varchar(255), `password` varchar(255), `email` varchar(255), `qb1` float DEFAULT 3.0, `qb2` float DEFAULT 0.5, `qb3` float DEFAULT 0.0, `rb1` float DEFAULT 10.0, `rb2` float DEFAULT 9.5, `rb3` float default 9.0, `rb4` float default 8.0, `rb5` float default 4.0, `rb6` float default 1.0, `rb7` float default 1.0, `rb8` float default 0.5, `rb9` float default 0.5, `rb10` float default 0.5, `wr1` float default 8.7, `wr2` float default 8.0, `wr3` float default 8.0, `wr4` float default 7.5, `wr5` float default 5.0, `wr6` float default 1.0, `wr7` float default 1.0, `wr8` float default 0.5, `wr9` float default 0.5, `wr10` float default 0.5, `te1` float DEFAULT 8.5, `te2` float DEFAULT 0.3, `k1` float DEFAULT 0.5, `k2` float DEFAULT 0.0, `de1` float DEFAULT 0.5, `de2` float DEFAULT 0.0, PRIMARY KEY(`username`)) ENGINE = memory;"
	userTable = "CREATE TABLE `users` (`username` varchar(255), `password` varchar(255), `email` varchar(255), `qb1` float DEFAULT 3.0, `qb2` float DEFAULT 0.6, `qb3` float DEFAULT 0.0, `qb4` float DEFAULT 0.0, `qb5` float DEFAULT 0.0, `qb6` float DEFAULT 0.0, `rb1` float DEFAULT 10.0, `rb2` float DEFAULT 9.6, `rb3` float default 9.0, `rb4` float default 8.0, `rb5` float default 4.0, `rb6` float default 1.0, `rb7` float default 1.0, `rb8` float default 0.6, `rb9` float default 0.6, `rb10` float default 0.6, `wr1` float default 8.8, `wr2` float default 8.0, `wr3` float default 8.0, `wr4` float default 7.6, `wr5` float default 5.0, `wr6` float default 1.0, `wr7` float default 1.0, `wr8` float default 0.6, `wr9` float default 0.6, `wr10` float default 0.6, `te1` float DEFAULT 8.6, `te2` float DEFAULT 0.4, `te3` float DEFAULT 0.0, `te4` float DEFAULT 0.0, `te5` float DEFAULT 0.0, `te6` float DEFAULT 0.0, `k1` float DEFAULT 0.6, `k2` float DEFAULT 0.0, `k3` float DEFAULT 0.0, `k4` float DEFAULT 0.0, `k5` float DEFAULT 0.0, `k6` float DEFAULT 0.0, `de1` float DEFAULT 0.6, `de2` float DEFAULT 0.0, `de3` float DEFAULT 0.0, `de4` float DEFAULT 0.0, `de5` float DEFAULT 0.0, `de6` float DEFAULT 0.0, PRIMARY KEY(`username`)) ENGINE = memory;"

#	cursor.execute("DROP TABLE `users`")
#	cursor.execute(userTable)
#	cursor.execute(addMe)

	cursor.execute("UPDATE rank_xls SET adp = 316 WHERE adp = 0;")
	cursor.execute("UPDATE de_xls SET adps = 32 WHERE adps = 0;")
	for item in plist:
#		cursor.execute("ALTER TABLE "+plist[item]+" ADD myadj float DEFAULT 0;")
#		cursor.execute("ALTER TABLE "+plist[item]+" ADD mydp float DEFAULT 0;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD prorank float DEFAULT 316;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD adp float DEFAULT 316;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD rank float DEFAULT 316;")
		cursor.execute("ALTER TABLE "+plist[item]+" ADD position varchar(255) DEFAULT '"+item+"';")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET prorank = rank_xls.average WHERE "+plist[item]+".player = rank_xls.player")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET "+plist[item]+".rank = rank_xls.rank WHERE "+plist[item]+".player = rank_xls.player")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET "+plist[item]+".adp = rank_xls.adp WHERE "+plist[item]+".player = rank_xls.player")

# not usable when loading saved rankings
#		cursor.execute("UPDATE "+plist[item]+", myVals SET myadj = myVals.value WHERE "+plist[item]+".player = myVals.player")
#		cursor.execute("UPDATE "+plist[item]+", myVals SET mydp = myVals.dpoints WHERE "+plist[item]+".player = myVals.player")
#		var = "UPDATE "+plist[item]+", myVals SET "+plist[item]+".rank = myVals.rank WHERE "+plist[item]+".player = myVals.player"
#		cursor.execute(var)


		if plist[item] in "de_xls":
			continue
		cursor.execute("ALTER TABLE "+plist[item]+" ADD bye_week float DEFAULT 0;")
		cursor.execute("UPDATE "+plist[item]+", rank_xls SET "+plist[item]+".bye_week = rank_xls.bye_week WHERE "+plist[item]+".player = rank_xls.player")

	cursor.execute("SELECT `username` FROM `users`")
	outusers = cursor.fetchall()
	for user in outusers:
		deleteOld = "DELETE FROM `myVals"+user['username']+"` WHERE NOT EXISTS (SELECT NULL FROM `rank_xls` WHERE `rank_xls`.player = `myVals"+user['username']+"`.player)"
		insertOld = "INSERT INTO `myVals"+user['username']+"` (player,rank) SELECT player,rank FROM rank_xls WHERE NOT EXISTS (SELECT NULL FROM `myVals"+user['username']+"` WHERE `rank_xls`.player = `myVals"+user['username']+"`.player)"
		updateOld = "UPDATE `myVals"+user['username']+"`, `rank_xls` SET `myVals"+user['username']+"`.rank = `rank_xls`.rank WHERE `myVals"+user['username']+"`.player = `rank_xls`.player"
		cursor.execute(deleteOld)
		cursor.execute(insertOld)
		cursor.execute(updateOld)


	connection.commit()

finally:
        connection.close()
