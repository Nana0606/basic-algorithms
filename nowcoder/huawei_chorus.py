# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/16 8:59

def getIncrease(data):
    increase = []
    increase.append(1)
    for i in range(1, N):
        increase.append(1)
        for j in range(i - 1, -1, -1):
            # 其实按照动态规划的思想，increase[i]最大的情况便是increase[i-1] + 1，所有and之后的限制相当于限制了最长递增子串
            if data[i] > data[j] and increase[i] < increase[j] + 1:
                increase[i] = increase[j] + 1
    return increase

if __name__ == '__main__':
    while True:
        try:
            N = int(input())
            data = list(map(int, [elem for elem in input().split(' ') if elem != '']))
            increase = getIncrease(data)
            print(increase)
            decrease = list(reversed(getIncrease(list(reversed(data)))))
            print(decrease)
            res = []
            for i in range(N):
                # 165 180 176这种情况是3，因为180共用了2次
                res.append(increase[i] + decrease[i]- 1)
            print(N - max(res))
        except:
            break







