# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-22 08:55

"""
注意这个题目是和1014：最小篮子重量一个类型的题目
1、首先可以确定的是最终的大小一定的[max，sum]之间
2、在max和sum之间进行二分查找，对应某一个mid值：
    计算如果最大sum是mid，则需要多少个子串(m)，将在mid条件下需要的子串个数记为count
        如果count > m，则说明mid条件下的子串数目较多，因此left = mid + 1
        否则，right = mid -1（注意：count==m仍然服从这个规则，因为是找到最小的最大sum，所以不能直接返回mid，需要继续查找找到一个最小的）
   返回left
"""

class Solution:
    def splitArray(self, nums, m: int) -> int:
        left = max(nums)
        right = sum(nums)
        if m == 1:
            return right
        while left <= right:
            total = 0
            mid = int((left + right) / 2)
            count = 1
            for num in nums:
                total += num
                if total > mid:
                    count += 1
                    total = num
                    if count > m:
                        left = mid + 1
            if count <= m:  # <= 因为是需要找到最小的最大sum
                right = mid - 1
        return left

if __name__ == '__main__':
    nums = [7, 2, 5, 10, 8]
    m = 2
    solution = Solution()
    res = solution.splitArray(nums, m)
    print(res)
