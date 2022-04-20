'''
Description: 
Version: 
Autor: guanzhou
email: guanzhou.cn@gmail.com
Date: 2022-03-18 17:43:01
LastEditors: guanzhou
LastEditTime: 2022-03-29 00:52:23
'''

def csv2txt(csvPath, txtPath):
    with open(csvPath) as csv:
        with open(txtPath, 'w+') as txt:

            preTick = 0
            realTick = 0

            for line in csv:
                sps = line.split(',')
                if(len(sps) != 5):
                    continue
                y = sps[0]
                x = sps[1]
                p = sps[3]
                t = sps[4][:-1]

                t = int(t)
                if(t < preTick):
                    realTick = realTick + preTick
                preTick = t
                t = t + realTick
                t = str(t)
                
                x = int(x)
                y = int(y)
                if(x + 1 <= 240 or x + 1 > 1040):
                    continue
                x = (x - 240) * 128 / 128
                y = y * 128 / 128

                x = int(x)
                y = int(y)
                x = str(x)
                y = str(y)
                string = t + ' ' + x + ' ' + y + ' ' + p + '\n'
                txt.write(string)
            pass
        pass
    pass


if __name__ == '__main__':
    csv2txt(r'../bin/test.csv', r'../bin/test.txt')