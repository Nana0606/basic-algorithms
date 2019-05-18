# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/14 11:03

"""
注意理解题意：
1、保存最后8个不一样的(文件姓名，行数)
2、输出的是对应的最后8个不一样的(文件姓名，行数)，在所有文件中出现的次数
"""
if __name__ == '__main__':
    data = []
    row = input()
    while row != "-1":
        try:
            data.append(row)
            row = input()
        except:
            break
    new_keys = []
    res = {}  # key is a tuple of (name, row_num, number)
    for elem in data:
        elems = elem.split(' ')
        if len(elems) == 2:
            file_name = elems[0].split("\\")[-1][-16:]
            row_num = elems[1]
            if (file_name, row_num) not in new_keys:
                new_keys.append((file_name, row_num))
            if res.get((file_name, row_num)):
                res[(file_name, row_num)] += 1
            else:
                res[(file_name, row_num)] = 1
    for key in new_keys[-8:]:
        print(key[0] + " " + key[1] + " " + str(res[key]))





