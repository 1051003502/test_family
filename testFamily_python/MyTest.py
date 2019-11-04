'''
随便测试 随便更改
'''
import threading
class FileSingleton:
    max=100      #最多提供多少个文件句柄
    __lock = threading.Lock()

    def getFp(self):
        FileSingleton.__lock.acquire()  # 锁上
        max+=100
        max-=100
        FileSingleton.__lock.release() #解锁
fileSingleton=FileSingleton()


class myThread(threading.Thread):  # 继承父类threading.Thread
    num=666
    lock=threading.Lock()
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):  # 把要执行的代码写到run函数里面 线程在创建后会直接运行run函数
        for i in range(100000):
            #myThread.lock.acquire()
            myThread.num=myThread.num+132465
            myThread.num=myThread.num-132465
            #myThread.lock.release()
# 创建新线程

if __name__=="__main__":
    thread1 = myThread()
    thread2 = myThread()
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()
    print (myThread.num)


