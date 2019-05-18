# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 21:36
import re

"""
注意：
加多组测试while True
加try-except，否则会报错没有进行错误检查
"""
if __name__ == '__main__':
    while True:
        try:
            content = [elem+";" for elem in input().split(';') if elem != '']   # 加上;是为了正则匹配
            x = 0
            y = 0
            for elem in content:
                if re.match(r'((A|W|S|D)\d{1,2});', elem):
                    if elem.startswith('A'):
                        x -= int(elem[1:-1])
                    elif elem.startswith('S'):
                        y -= int(elem[1:-1])
                    elif elem.startswith('W'):
                        y += int(elem[1:-1])
                    elif elem.startswith('D'):
                        x += int(elem[1:-1])
            print(str(x).strip()+','+str(y).strip())
        except:
            break
