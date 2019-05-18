# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-16 15:35


"""
本题目主要分两种情况：一种是有中心点的回头序列，一种是没有中心点的回文序列
"""

def longestPalindrome(content, i):
    """
    以第i个元素为中心点
    :param content:
    :param i:
    :return:
    """
    """以i为空心点"""
    left1 = i-1
    right1 = i+1
    leng1 = 1
    while left1 >=0 and right1 <= len(content) - 1 and content[left1] == content[right1]:
        leng1 += 2
        left1 -= 1
        right1 += 1

    # 以i-1和i中间的位置为中心点
    left2 = i - 1
    right2 = i
    leng2 = 0
    while left2 >= 0 and right2 <= len(content) - 1 and content[left2] == content[right2]:
        leng2 += 2
        left2 -= 1
        right2 += 1
    print("leng1::%d, leng2::%d" % (leng1, leng2))
    return max(leng1, leng2)

if __name__ == '__main__':
    while True:
        try:
            content = input()
            len_lis = []  # 分别代表以第0个元素，第1个元素，第2个元素为中心点获取到的最长回文序列

            len_lis.append(0)     # 第一个元素为中心点
            for i in range(1, len(content) - 1):
                res = longestPalindrome(content, i)
                len_lis.append(res)
            len_lis.append(0)    # 最后一个元素为中心点
            print(max(len_lis))
        except:
            break