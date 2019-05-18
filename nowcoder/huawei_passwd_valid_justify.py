# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/15 21:43

# 长度超过8位
def isLenGreater8(content):
    return True if len(content) > 8 else False

# 包括大小写字母、数字.其它符号,以上四种至少三种
def isContainChara(content):
    number = 0
    lower_chara = 0
    upper_chara = 0
    other = 0
    for elem in list(content):
        if elem >= 'a' and elem <= 'z':
            lower_chara = 1
        elif elem >= 'A' and elem <= 'Z':
            upper_chara = 1
        elif elem >= '0' and elem <= '9':
            number = 1
        else:
            other  = 1
    return True if (lower_chara + upper_chara + number + other ) >= 3 else False

def notCommonSubstr(content):
    for i in range(0, len(content) - 2):
        substr = content[i: i + 3]
        if substr in content[i+3:]:
            return False
    return True

if __name__ == '__main__':
    while True:
        try:
            content = input()
            if isLenGreater8(content) and isContainChara(content) and notCommonSubstr(content):
                print("OK")
            else:
                print("NG")
        except:
            break
