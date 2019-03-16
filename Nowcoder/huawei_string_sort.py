# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/18 9:36
"""
解题思路：只需要使用存储的方式便可以
将字母按需存入，为保证非字母顺序不变，所以引入了一个临时数组
"""
if __name__ == '__main__':
    while True:
        try:
            content = list(input())
            sort_v = []
            for i in range(26):
                for j in range(len(content)):
                    if ord(content[j]) - ord('a') == i or ord(content[j]) - ord('A') == i:
                        sort_v.append(content[j])
            idx = 0
            for i in range(len(content)):
                if (content[i] >= 'a' and content[i] <= 'z') or (content[i] >= 'A' and content[i] <= 'Z'):
                    content[i] = sort_v[idx]
                    idx += 1
            print(''.join(content))
        except:
            break
