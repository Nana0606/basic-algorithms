# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/16 8:45

if __name__ == '__main__':
    number = int(input())
    while number != 0:
        try:
            # handle
            counter = 0
            while number >= 3:
                counter += 1
                number -= 3   # 3瓶
                number += 1   # 换1瓶
            if number == 2:
                counter += 1
            print(counter)
            # get the next data
            number = int(input())
        except:
            break