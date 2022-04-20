'''
Descripttion: 
version: 
Author: guanzhou
Date: 2021-01-08 21:38:39
LastEditors: guanzhou
LastEditTime: 2021-01-08 21:42:11
'''
import syszux as s

c = s.CivilNet('dd')
a=c.getName()
print(a)

c.setName('ddddd')
print(c.getName())