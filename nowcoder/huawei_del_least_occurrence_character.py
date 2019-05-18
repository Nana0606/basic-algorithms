# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/16 8:53
if __name__ == '__main__':
    while True:
        try:
            content = input()
            chara_map = {}
            for elem in list(content):
                if chara_map.get(elem):
                    chara_map[elem] += 1
                else:
                    chara_map[elem] = 1
            min_val = min(chara_map.values())
            for key, value in chara_map.items():
                if value == min_val:
                    content = content.replace(key, '')
            print(content)
        except:
            break