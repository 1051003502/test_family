from flask import Flask
from flask import request
app = Flask(__name__)

@app.route('/get/getSum')
def hello_world():
    args=request.args
    return str(int(args['a'])+int(args['b']))

if __name__ == '__main__':
    app.run("0.0.0.0",debug=True,port=62001)
