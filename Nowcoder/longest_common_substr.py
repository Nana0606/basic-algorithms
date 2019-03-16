# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/17 12:30
def CommonStr(str1, num1, str2, num2):
    dp = [[0] * (num1 + 1) for i in range(num2+1)]
    max = 0
    for i in range(1, num2+1):
        for j in range(1, num1+1):
            if str2[i-1] == str1[j-1]:
                dp[i][j] = dp[i-1][j-1] + 1
            else:
                dp[i][j] = 0
            if max < dp[i][j]:
                max = dp[i][j]
    return max



if __name__ == '__main__':
    contents = [elem for elem in input().split(",") if elem != '']
    str1 = contents[0]
    num1 = int(contents[1])
    str2 = contents[2]
    num2 = int(contents[3])
    print("str1::%s, num1:%d, str2: %s, num2: %d" % (str1, num1, str2, num2))
    max = CommonStr(str1, num1, str2, num2)
    print(max)