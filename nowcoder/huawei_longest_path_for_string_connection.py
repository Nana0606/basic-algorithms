# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 21:26
if __name__ == '__main__':
    number = int(input())
    lis= []
    for i in range(number):
        lis.append(input())
    list.sort(lis)
    for elem in lis:
        print(elem)