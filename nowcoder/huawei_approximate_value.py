# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 20:39
if __name__ == '__main__':
    number = input()
    if '.' not in number:
        print(number)
    else:
        inte = number.split('.')[0]
        decimial_first = number.split('.')[1][0]
        if int(decimial_first) >= 5:
            print(int(inte) + 1)
        else:
            print(int(inte))