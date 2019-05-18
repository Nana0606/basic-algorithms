# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-19 10:43

class Solution:
    def lengthOfLIS(self, nums) -> int:
        if len(nums) == 0:
            return 0
        increase = [0] * len(nums)
        for i in range(0, len(nums)):
            cur_max = 1
            for j in range(0, i):
                if nums[i] > nums[j] and cur_max < increase[j] + 1:
                    cur_max = increase[j] + 1
            increase[i] = cur_max
        return max(increase)

if __name__ == '__main__':
    # nums = [10, 9, 2, 5, 3, 7, 101, 18]
    nums = []
    solution = Solution()
    res = solution.lengthOfLIS(nums)
    print(res)
