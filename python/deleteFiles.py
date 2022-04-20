'''
Descripttion: 
version: 
Author: guanzhou
Date: 2021-07-27 16:13:28
LastEditors: guanzhou
LastEditTime: 2021-12-12 10:16:15
'''
'''
Descripttion: 
version: 
Author: guanzhou
Date: 2021-07-27 16:13:28
LastEditors: guanzhou 
LastEditTime: 2021-07-27 16:30:24
'''
import os
import shutil

imgName = "/EventStream.bin"
subDir = "/img40000"



for A in range(43):
    # dirTarget = './action_data/image/train/' + str(A) + '/'
    # os.mkdir(dirTarget)
    # count = 0

    pathA = "./action_data/computer1/"
    if(A<10):
        pathA += "A000"
        pathA += str(A)
    else:
        pathA += "A00"
        pathA += str(A)
    for P in range(32):
        if(P<10):
            pathP = pathA + "P000"
            pathP += str(P)
        else:
            pathP = pathA + "P00"
            pathP += str(P)

        for S in range(4):
            pathS = pathP + "/S0"
            pathS += str(S)
            pathS += subDir

                
            # 删除文件夹
            if(os.path.exists(pathS)):
                files = os.listdir(pathS)
                for file in files:
                    path = pathS+"/"+file
                    if(os.path.exists(path)):
                        os.remove(path)
                os.removedirs(pathS)

            # # 删除文件
            # if(os.path.exists(pathS)):
            #     os.remove(pathS)

            # # 拷贝
            # pathTarget = dirTarget  + str(count) + '.txt'
            # if(os.path.exists(pathS)):
            #     count += 1
            #     shutil.copy(pathS, pathTarget)
            #     os.remove(pathS)

print("finished\n")