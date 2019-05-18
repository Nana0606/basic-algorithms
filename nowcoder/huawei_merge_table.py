# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 20:54

if __name__ == '__main__':
    number = int(input())
    res = {}
    for i in range(number):
        current = input().split(' ')
        current_index = int(current[0])
        current_value = int(current[1])
        # print("current_index is:: %d, current_value is:%d" % (current_index, current_value))
        if res.get(current_index):
            res[current_index] += current_value
        else:
            res[current_index] = current_value
        # print("i is:: %s, res is:: %s" % (str(i), str(res)))
    res_new = sorted(res.items(), key=lambda x: x[0], reverse=False)
    for key, value in res_new:
        print(str(key) + " " + str(value))
