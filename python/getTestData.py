'''
Description: 
Version: 
Autor: guanzhou
email: guanzhou.cn@gmail.com
Date: 2021-11-04 13:53:30
LastEditors: guanzhou
LastEditTime: 2022-03-06 15:21:42
'''
import os
import random
import time
import shutil

path = "/home/tuto/Event/data/downsample/train/"
testPath = "/home/tuto/Event/data/downsample/test/"

for i in range(5):
    folder = path + str(i) + '/'
    testFolder = testPath + str(i) + '/'
    if not os.path.exists(testFolder):
        os.mkdir(testFolder)
    if not os.path.exists(folder):
        continue
    listFile = os.listdir(folder)
    
    temp = []
    for item in listFile:
        filePath = os.path.join(folder,item)
        if os.path.isfile(filePath):
            temp.append(filePath)

    ticks = time.time()
    random.seed(int(round(ticks * 1000)))
    slice = random.sample(temp,int(len(temp) * 0.2))
    
    for item in slice:
        # shutil.copy(item,testFolder)
        shutil.move(item,testFolder)
