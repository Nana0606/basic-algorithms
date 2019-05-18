# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-15 12:13

"""
本题总结：
1、规则太多
2、注意用while(True)，否则会说输入为空
3、注意使用try except，否则会说是数组越界之类的
"""

def process(elem):
    shijinzhi = int(elem, 16)   # 16转化为10进制
    erjinzhi = str(bin(shijinzhi))   # 10进制转2进制
    temp = erjinzhi[2:]             # [2:]去掉0x、od之类的      
    if len(temp) == 3:      # 若不够4位，默认使用3位，但是题目要求必须是4位，这里加个0     j
        temp = '0' + temp
    elif len(temp) == 2:
        temp = '00' + temp
    elif len(temp) == 1:
        temp = '000' + temp
    lis = list(temp)
    lis.reverse()
    reversed = ''.join(lis)
    shijin_reverse = int(reversed, 2)     # 2进制转10进制
    res = hex(shijin_reverse)[2:]         # 10进制转16进制
    return res.upper()



if __name__ == '__main__':
    while(True):
        try:
            a, b = input().split(' ')
            res = a + b
            new_res_ou = ""
            new_res_ji = ""
            i = 0
            for elem in res:
                if i % 2 == 0:
                    new_res_ou += elem
                    i += 1
                else:
                    new_res_ji += elem
                    i += 1
            new_res_ou_lis = list(new_res_ou)
            new_res_ou_lis.sort()
            new_res_ji_lis = list(new_res_ji)
            new_res_ji_lis.sort()
            i = 0
            new_res = ''
            for i in range(0, len(new_res_ou) - 1):
                elem_ou  = new_res_ou_lis[i]
                elem_ji  = new_res_ji_lis[i]
                if (elem_ou >= '0' and elem_ou <= '9') or (elem_ou >= 'A' and elem_ou <= 'F') or (elem_ou >= 'a' and elem_ou <= 'f'):
                    new_res += process(elem_ou)
                else:
                    new_res += elem_ou
                if (elem_ji >= '0' and elem_ji <= '9') or (elem_ji >= 'A' and elem_ji <= 'F') or (elem_ji >= 'a' and elem_ji <= 'f'):
                    new_res += process(elem_ji)
                else:
                    new_res += elem_ji
            elem_ou = new_res_ou_lis[len(new_res_ou) - 1]
            if (elem_ou >= '0' and elem_ou <= '9') or (elem_ou >= 'A' and elem_ou <= 'F') or (elem_ou >= 'a' and elem_ou <= 'f'):
                new_res += process(elem_ou)
            else:
                new_res += elem_ou
            if len(new_res_ou_lis) == len(new_res_ji_lis):
                elem_ji  = new_res_ji_lis[len(new_res_ou) - 1]
                if (elem_ji >= '0' and elem_ji <= '9') or (elem_ji >= 'A' and elem_ji <= 'F') or (elem_ji >= 'a' and elem_ji <= 'f'):
                    new_res += process(elem_ji)
                else:
                    new_res += elem_ji
            print(new_res)
        except:
            break
