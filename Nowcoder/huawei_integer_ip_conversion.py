# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-16 15:51

def ipToInteger(content):
    """
    将IP转换为整数
    :param content:
    :return:
    """
    ips = [int(elem) for elem in content.split('.') if elem != '']
    erjinzhi_all = ""
    for ip in ips:
        erjinzhi = bin(ip)[2:]   # 十进制转二进制
        erjinzhi = erjinzhi.zfill(8)
        erjinzhi_all += erjinzhi
    return int(erjinzhi_all, 2)   # 二进制转十进制

def integerToIP(content):
    """
    将整数转化为IP
    :param content:
    :return:
    """
    erjinzhi_all = bin(int(content))[2:]   # 十进制转二进制
    erjinzhi_all = erjinzhi_all.zfill(32)
    erjinzhis = [erjinzhi_all[0: 8], erjinzhi_all[8: 16], erjinzhi_all[16: 24], erjinzhi_all[24: 32]]
    res = ""
    for erjinzhi in erjinzhis:
        shijizhi = int(erjinzhi, 2)  # 二进制转十进制
        res += str(shijizhi) + "."
    return res[0: -1]


if __name__ == '__main__':
    while True:
        try:
            content = input()
            if '.' in content:
                res = ipToInteger(content)
            else:
                res = integerToIP(content)
            print(res)
        except:
            break