from flask import Flask

app = Flask(__name__)
app.debug = True
if __name__=="__main__":
	app.run(host='0.0.0.0', debug=True)

app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

from app import views
