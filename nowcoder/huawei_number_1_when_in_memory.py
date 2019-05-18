# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 21:32
if __name__ == '__main__':
    number = int(input())
    binary = bin(number).replace('0b', '')
    print(binary.count('1'))