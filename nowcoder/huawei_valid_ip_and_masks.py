# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/10 14:08

"""
通过率：50%
A类多出2个，D类多出1个
"""

def isip(ip):
    elems = [elem for elem in ip.split('.') if elem != '.']
    flag_error = 0
    if len(elems) == 4:
        if elems[0] == '0':
            return False
        for elem in elems:
            if not( elem.isdigit() and int(elem) >=0 and int(elem) <= 255):
                flag_error = 1
        if flag_error == 0:
            return True
    return False

def ismask(mask):
    mask_elems = [elem for elem in mask.split('.') if elem != '']
    all_mask_bin = ''
    if len(mask_elems) == 4:
        for elem in mask_elems:
            all_mask_bin += bin(int(elem)).replace('0b', '')
    index = all_mask_bin.find('0')
    if index == -1 or index == 0:
        return False
    for i in range(index, len(all_mask_bin)):
        if all_mask_bin[i] == '1':
            return False
    return True


if __name__ == '__main__':
    A = 0
    B = 0
    C = 0
    D = 0
    E = 0
    error = 0
    private = 0
    content = input()
    while content:
        try:
            record = content.split('~')
            ip = record[0]
            mask = record[1]
            if not (isip(ip) and ismask(mask)):
                error += 1
            else:  # ip是有效的
                ip_elems = ip.split('.')
                head = int(ip_elems[0])
                if head >= 1 and head <= 126:
                    A += 1
                    if head == 10:
                        private += 1
                elif head >= 128 and head <= 191:
                    B += 1
                    if head == 192 and int(ip_elems[1]) >= 16 and int(ip_elems[1]) >= 31:
                        private += 1
                elif head >= 192 and head <= 223:
                    C+= 1
                    if head == 192 and int(ip_elems[1]) == 168:
                        private += 1
                elif head >= 224 and head <= 239:
                    D += 1
                elif head >= 240 and head <= 255:
                    E +=1
            content = input()
        except:
            break
    print(str(A) + " " + str(B) + " " + str(C) + " " + str(D) + " " + str(E) + " " + str(error) + " " + str(
                    private))




