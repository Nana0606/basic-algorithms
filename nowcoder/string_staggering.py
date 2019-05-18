# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/17 14:55

"""
代码思想：动态规划

如果str1的长度为M, str2的长度为N，可以利用经典的动态规划的方法可以达到时间复杂度为O(MN), 额外空间复杂度为O(MN)。
方法：aim的长度一定为 M+N，否则返回 false. 生成(M+1)x(N+1)的布尔类型的矩阵dp, 
     dp[i][j]表示 aim[0...i+j-1] 能否被 str1[0...i-1] 和 str2[0...j-1]交错组成。
     从左到右，从上到下计算，结果即为 dp[M][N]的值
更新策略：
     1. dp[0][0] = true;
     2. 矩阵dp第一列 dp[0...M-1][0] , dp[i][0] 表示 aim[0...i-1] 能否被 str1[0...i-1]组成，若
        aim[0...i-1] == str1[0...i-1]，dp[i][0] = true ;
     3. 矩阵dp第一行 dp[0][0...N-1]，dp[0][j] 表示 aim[0...j-1] 能否被 str2[0...j-1]组成，若
        aim[0...j-1] == str2[0..j-1], dp[0][j] = true;
     4. 其他位置的更新：
        dp[i][j] 的更新依赖于 dp[i-1][j] 与 dp[i][j-1]的结果，现做以下判断：
        (1) dp[i-1][j] 代表 aim[0..i+j-2] 能否被 str1[0...i-2] 和 str2[0...j-1]交错组成，如果可以（dp[i-1][j] = true），再在满足
            str1[i-1] == aim[i+j-1] 则 dp[i][j] = true.
        (2) dp[i][j-1] 代表 aim[0..i+j-2] 能否被 str1[0...i-1] 和 str2[0...j-2]交错组成，如果可以 （dp[i][j-1] = true），再在满足
            str2[j-1] == aim[i+j-1] 则 dp[i][j] = true.
        (3) 若(1)(2)均不满足，则 dp[i][j] = false.
---------------------
作者：忆几度长安
来源：CSDN
原文：https://blog.csdn.net/s448312891/article/details/80361364
版权声明：本文为博主原创文章，转载请附上博文链接！

"""

def isStaggering(str1, num1, str2, num2, str3, num3):
    # str3为目标值，str1和str2为加数
    if num3 != (num1+ num2):
        return False
    # 创建dp数目，维度为（num1+1）*（num2+1）
    dp = [[False for j in range(num2 + 1)] for i in range(num1 + 1)]   # dp初始化
    dp[0][0] = True
    for i in range(1, num1 + 1):   # 处理第一列元素值
        if str1[0: i] == str3[0: i]:
            dp[i][0] = True
    for j in range(1, num2 + 1):   # 处理第一行元素值
        if str2[0: j] == str3[0: j]:
            dp[0][j] = True
    for i in range(1, num1 + 1):
        for j in range(1, num2 + 1):
            dp[i][j] = (dp[i-1][j]==True and str1[i-1] == str3[i + j - 1]) or (dp[i][j-1]==True and str2[j-1] == str3[i + j - 1])
    return dp[num1][num2]


if __name__ == '__main__':
    contents = [elem for elem in input().split(',') if elem != ' ']
    str1 = contents[0][1:-1]
    num1 = int(contents[1])
    str2 = contents[2][1:-1]
    num2 = int(contents[3])
    str3 = contents[4][1:-1]
    num3 = int(contents[5])
    print("str1::", str1, " str2::", str2, " str3::", str3)
    res = isStaggering(str1, num1, str2, num2, str3, num3)
    print(res)



