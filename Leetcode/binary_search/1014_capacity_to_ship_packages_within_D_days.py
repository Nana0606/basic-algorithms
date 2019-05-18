# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-19 10:04

"""
算法思路：
首先可以确定的是篮子的大小一定在[max(weights)，sum(weights)]之间，下面在这个范围内遍历二分查找
1、首先确定一个当前值mid = (left + right) / 2，然后看在篮子为mid大小的情况下，需要多少篮子
2、如果need <= D，也就是说这时候可以减小篮子的重量，否则增加篮子的储物量
"""

class Solution:
    def shipWithinDays(self, weights, D: int) -> int:
        left = max(weights)
        right = sum(weights)
        while left < right:
            mid = int((left + right) / 2)
            need = 1   # need表示计算在篮子大小为mid的情况下，需要多少天才可以完成任务
            current = 0 # current是为了存储当前这一个篮子里面已经有多少重量
            # 下面的遍历是为了确定在mid这个容量下，需要多少个篮子
            for w in weights:
                if current + w > mid:
                    need += 1
                    current = 0
                current += w
            if need <= D:
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == '__main__':
    weights = [1,2,3,4,5,6,7,8,9,10]
    D = 5
    solution = Solution()
    res = solution.shipWithinDays(weights, D)
    print(res)
