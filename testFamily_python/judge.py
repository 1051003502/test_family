import os
from fileOperate import fileSingleton as fs  #得到文件句柄
class JudgeFactory:
    def get(self,name):
        if(name=="cpp"):
            return self.cppSolution
        if(name=="python"):
            return self.pySolution
        if(name=="java"):
            return self.javaSolution
        if (name == "golang"):
            return self.golangSolution
    def programmeRun(self,runType,exe,infile,out,er):
        os.system("{ timeout 5 %s %s;} 0<%s 1>%s 2>%s" % (runType,exe, infile, out, er))
        with open(er, "r") as fp:  # 查看er文件是否有信息
            res = fp.read()
        if (res != ""):  # 运行错误 直接返回
            return res
        with open(out, "r") as fp:
            res = fp.read()
        return res;

    def cppSolution(self,codedata, indata):
        dir = fs.getfp()  # pogrammeData/0 拿一个可用dir
        cpp = dir + "/a.cpp"
        exe = dir + "/a.exe"
        infile = dir + "/a.in"
        out = dir + "/a.out"
        er = dir + "/a.er"
        # codedata、indata写入文件
        with open(cpp, "w") as fp:
            fp.write(codedata)
        with open(infile, "w") as fp:
            fp.write(indata)
        # 用g++命令编译cpp ->exe  错误信息重定向到er
        os.system("g++ %s -o %s 2>%s" % (cpp, exe, er))
        res = ""
        with open(er, "r") as fp:  # 看下有没有编译出错
            res = fp.read()
        if (res != ""):  # 编译错误 直接返回
            return res
        # 执行exe 输入重定向为infile 标准输入重定向out 错误输出重定向er
        res = self.programmeRun("",exe,infile,out,er)
        return res  # 返回标准输出

    def pySolution(self,codedata, indata):
        dir = fs.getfp()  # pogrammeData/0 拿一个可用dir
        py=dir+"/a.py" #源代码文件
        infile= dir + "/a.in"#输入文件
        out = dir + "/a.out" #输出文件
        er = dir + "/a.er"   #错误输入文件
        with open(py, "w") as fp:
            fp.write(codedata)
        with open(infile, "w") as fp:
            fp.write(indata)
        res=self.programmeRun("python3",py,infile,out,er)
        return res
    def javaSolution(self,codedata,indata):
        dir = fs.getfp()  # pogrammeData/0 拿一个可用dir
        java = dir + "/TestJava.java"  # 源代码文件
        infile = dir + "/a.in"  # 输入文件
        out = dir + "/a.out"  # 输出文件
        classfile = "TestJava"
        er = dir + "/a.er"  # 错误输入文件
        with open(java, "w") as fp:
            fp.write(codedata)
        with open(infile, "w") as fp:
            fp.write(indata)
        os.system("javac %s  2>%s" % (java, er))
        res = ""
        with open(er, "r") as fp:  # 看下有没有编译出错
            res = fp.read()
        if (res != ""):  # 编译错误 直接返回
            return res
        res = self.programmeRun("java -classpath "+dir, classfile, infile, out, er)
        return res  # 返回标准输出
    def golangSolution(self,codedata,indata):
        dir = fs.getfp()  # pogrammeData/0 拿一个可用dir
        golang=dir+"/a.go"
        infile = dir + "/a.in"  # 输入文件
        out = dir + "/a.out"  # 输出文件
        er = dir + "/a.er"  # 错误输入文件
        with open(golang, "w") as fp:
            fp.write(codedata)
        with open(infile, "w") as fp:
            fp.write(indata)
        res = self.programmeRun("go run ", golang, infile, out, er)
        return res
judgeFactory=JudgeFactory()


