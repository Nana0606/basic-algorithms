# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 21:12
if __name__ == '__main__':
    content = input()
    lis = []
    dict_isexist = {}
    for i in range(1, len(content) + 1):
        current = content[len(content) - i]
        if not dict_isexist.get(current):
            dict_isexist[current] = 1
            lis.append(current)
    print(''.join(lis))
