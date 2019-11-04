from flask import Flask
from flask import request
import base64  #编码解码
import json    #编码解码
from judge import judgeFactory  #运行用户代码的解决方案

app = Flask(__name__)

@app.route('/post/judge/<codeType>',methods=['POST'])
def solve1(codeType):

    data1=request.get_data().decode("utf-8")
    dic = json.loads(data1) #json->字典
    codedata=base64.b64decode(dic['code']).decode("utf-8") #base64.b64decode 解码
    indata=base64.b64decode(dic['in']).decode("utf-8")

    solution = judgeFactory.get(codeType) #根据username得到solution
    res=solution(codedata,indata)
    return res
if __name__ == '__main__':
    app.run("0.0.0.0",debug=True,port=62002,threaded=True)
