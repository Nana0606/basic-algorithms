# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 19:23
if __name__ == '__main__':
    for i in range(2):
        content = input()
        for j in range(7):
            content += '0'
        for epoch in range(0, int(len(content)/8)):
            print(content[8*epoch:8*(epoch+1)])