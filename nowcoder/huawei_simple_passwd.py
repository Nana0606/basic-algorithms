# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/15 22:05
if __name__ == '__main__':
    while True:
        try:
            res = ""
            content = input()
            chara_number = {
                "1": "1",
                "a": "2",
                "b": "2",
                "c": "2",
                "d": "3",
                "e": "3",
                "f": "3",
                "g": "4",
                "h": "4",
                "i": "4",
                "j": "5",
                "k": "5",
                "l": "5",
                "m": "6",
                "n": "6",
                "o": "6",
                "p": "7",
                "q": "7",
                "r": "7",
                "s": "7",
                "t": "8",
                "u": "8",
                "v": "8",
                "w": "9",
                "x": "9",
                "y": "9",
                "z": "9",
                "0": "0"
            }
            for elem in list(content):
                if elem >= '0' and elem <= '9':
                    res += elem
                    print("第一个if::", res)
                elif elem >= 'a' and elem <= 'z':
                    res += chara_number.get(elem)
                    print("第二个if::", res)
                elif elem >= 'A' and elem <= 'Y':
                    # ord用于转化为ascill码，chr用于转化为字符
                    res += chr(ord(elem) + 1).lower()
                    print("第三个if::", res)
                elif elem == 'Z':
                    res += 'a'
                    print("第四个if::",res)
            print(res)
        except:
            break