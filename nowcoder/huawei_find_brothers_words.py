# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/18 10:32

def isBrothers(element, target):
    if element == target:
        return False
    if sorted(element) == sorted(target):
        return True


if __name__ == '__main__':
    contents = [elem for elem in input().split(' ') if elem != '']
    total_number = int(contents[0])
    candidate = contents[1:1+total_number]
    target = contents[-2]
    order = int(contents[-1])
    brothers = []
    for i in range(total_number):
        if isBrothers(candidate[i], target):
            brothers.append(candidate[i])
    brothers_sort = sorted(brothers)
    print("brothers_sort is::", brothers_sort)
    print("order is::", order)
    if order - 1 < len(brothers_sort):   # 必须判断边界
        print(str(len(brothers)), "\n", brothers_sort[order - 1])
    else:  # 注意输出格式：加换行
        print(str(len(brothers)))

