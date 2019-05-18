# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-17 10:41
"""
思路：正常思路是因为限制i<j，所以确定i，然后遍历后面的j
但是本题使用了动态规划，也就是我们确定j，然后找i<j的i，使其满足要求，这样在下次的迭代中，上次的结果加上当前的结果便可以使用
res += c[-t % 60]，确定一个j，求i<j，满足要求
c[t % 60] += 1便是把当前元素添加到c中，更新c
"""

class Solution:
    def numPairsDivisibleBy60(self, time) -> int:
        c = [0] * 60
        res = 0
        for t in time:
            res += c[-t % 60]
            c[t % 60] += 1
        return res

if __name__ == '__main__':
    seq = [30, 20, 150, 100, 40]
    solution = Solution()
    res = solution.numPairsDivisibleBy60(seq)
    print(res)
