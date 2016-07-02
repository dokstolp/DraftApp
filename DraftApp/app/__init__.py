from flask import Flask

app = Flask(__name__)
app.debug = True
if __name__=="__main__":
	app.run(host='0.0.0.0', debug=True)

app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

#@app.before_request
#def db_connect():
#	connection = pymysql.connect(host='localhost',
#                             user='root',
#                             password='ILikeToBrew!14',
#                             db='NFL_Draft',
#                             charset='utf8mb4',
#			     local_infile=True,
#                             cursorclass=pymysql.cursors.DictCursor)

#@app.teadown_request
#def db_disconnect(exception=None):
#	connection.close()

from app import views
