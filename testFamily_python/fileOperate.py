'''
得到一个文件名 单例模式
'''
import os
import shutil #删除目录
import threading #加锁
class FileSingleton:
    __max=100      #最多提供多少个文件句柄
    __fpindex=0    #接下来提供的文件的文件名  0 1 2 3......

    def __init__(self,fileName):
        FileSingleton.__lock = threading.Lock()
        FileSingleton.fileName=fileName
        if(os.path.exists(fileName)):
            shutil.rmtree(fileName) # 空目录、有内容的目录都可以删
        os.mkdir(fileName)      #新建目录
    def getfp(self):  #得到文件目录
        FileSingleton.__lock.acquire()  # 锁上
        fileName=FileSingleton.fileName
        file=fileName+'/'+str(FileSingleton.__fpindex)
        FileSingleton.__fpindex += 1;  # 下次打开的文件要+1
        FileSingleton.__lock.release() #解锁
        os.mkdir(file)
        return file;
    def __del__(self):

        #析构时把所有文件删除 也可以加个处理函数 处理完再删除
        return
fileSingleton=FileSingleton('programmeData')  #建立一个对象 由于python模块特性 这里实现了单例模式
if __name__=='__main__':
    print (fileSingleton.getfp())
