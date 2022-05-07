'''
Description: 
Version: 
Autor: guanzhou
email: guanzhou.cn@gmail.com
Date: 2022-03-29 00:26:32
LastEditors: guanzhou
LastEditTime: 2022-05-07 20:42:27
'''
from PIL import Image
import os

def deleteFolder(folder = './img'):
    print('begin to delete floder\n')
    for filename in os.listdir(folder):
        os.remove(folder + '/' + filename)
    print('finish delete floder\n')
    print('=='*30)
    pass

def showImg(filePath, ticksPerFrame = 40000, size = 128): #40000  40000000
    beginTick = 0
    countPic = 0
    img = Image.new('RGB',(size,size),(0,0,0))
    for count, line in enumerate(open(filePath, 'r')):
        splited = line.split()
        tick = int(splited[0])
        x = int(splited[1])
        y = int(splited[2])
        p = int(splited[3])
        
        if(count == 0):
            beginTick = tick
            pass
        if((tick - beginTick) / ticksPerFrame > countPic):
            img.save(r'../img/img' + str(countPic) + '.jpg')
            img = Image.new('RGB',(size,size),(0,0,0))
            countPic += 1
            pass
        if(p == 1):
            # img.putpixel((x, size - 1 - y),(0,0,255))
            img.putpixel((y, size - 1 - x),(0,0,255))
            
        else:
            # img.putpixel((x, size - 1 - y),(255,0,0))
            img.putpixel((y, size - 1 - x),(255,0,0))
        pass
    img.save(r'../img/img' + str(countPic) + '.jpg')
    pass

if __name__ == '__main__':
    # deleteFolder()
    # showImg('/media/hdd0/guanzhou/data/DvsGesture/txt/1/100.txt')
    showImg(r'../bin/datasettxt/00/6.txt',size = 800)
    pass