# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-16 16:12
if __name__ == '__main__':
    while True:
        try:
            content = input()
            content_lis = list(content)
            content_lis.sort()
            print(''.join(content_lis))
        except:
            break