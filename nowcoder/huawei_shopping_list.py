# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/14 9:07

if __name__ == '__main__':
    first_row = input().split(' ')
    N = int(first_row[0])   # 总钱数
    m = int(first_row[1])   # 希望购买的物品数
    v = []
    p_value = []
    q = []
    for i in range(0, m):
        basic = list(map(int, input().split(' ')))
        v.append(basic[0])
        p_value.append(basic[1] * basic[0])
        q.append(basic[2])
    dp = []
    temp = []
    for i in range(N+1):
        temp.append(0)
    for i in range(m+1):
        dp.append(temp)
    for i in range(1, m+1):
        for j in range(1, N+1):
            if q[i - 1] == 0:
                if v[i - 1] <= j:
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i - 1]] + p_value[i - 1])
            else:
                if v[i - 1] + v[q[i - 1]] <= j:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i-1]] + p_value[i - 1])
    for i in range(1, m+1):
        for j in range(1, N+1):
            print(str(dp[i][j]) + " ", end='')
        print(';')
    print(dp[m][N])

