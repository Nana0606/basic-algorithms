# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 19:32
if __name__ == '__main__':
    while True:
        try:
            hex_str = input()
            if len(hex_str) <= 2:
                print(0)
            else:
                hex_str = hex_str[2:].lower()
                ten = 0
                hex_dict = {
                    '0': 0,
                    '1': 1,
                    '2': 2,
                    '3': 3,
                    '4': 4,
                    '5': 5,
                    '6': 6,
                    '7': 7,
                    '8': 8,
                    '9': 9,
                    'a': 10,
                    'b': 11,
                    'c': 12,
                    'd': 13,
                    'e': 14,
                    'f': 15
                }
                for i in range(1, len(hex_str)+1):
                    ten += hex_dict[hex_str[-i]] * pow(16, i-1)
                print(ten)
        except:
            break

