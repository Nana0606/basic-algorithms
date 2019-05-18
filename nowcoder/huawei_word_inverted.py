# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-16 15:13

if __name__ == '__main__':
    content = input()
    new_content = ""
    for elem in content:
        if (elem >= 'a' and elem <= 'z') or (elem >= 'A' and elem <= 'Z'):
            new_content += elem
        else:
            new_content += ' '
    content_lis = [elem.strip() for elem in new_content.strip().split(' ') if elem != '']
    res = ""
    for i in range(len(content_lis)-1, 0, -1):
        res += content_lis[i]
        res += ' '
    res += content_lis[0]
    print(res)
