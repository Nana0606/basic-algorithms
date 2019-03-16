# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 19:14
"""
必须加入try-except
"""
if __name__ == '__main__':
    while True:
        try:
            n = int(input())
            numbers = set()
            for i in range(n):
                numbers.add(int(input()))
            sort_numbers = sorted(list(numbers))
            for elem in sort_numbers:
                print(elem)
        except:
            break