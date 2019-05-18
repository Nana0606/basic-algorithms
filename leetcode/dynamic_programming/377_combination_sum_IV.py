# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-22 11:10
"""
思路：如果已知i-1及其之前的数据可以被组成多少组合，则再求对应target=i的情况。
    ①初始化：dp[0]=1,这种情况是target=nums[i]，相当于是结束的
    ②更新方程：
        对于某一个target，如果已知元素num，则dp[target-num]的组合数便是dp[target]的组合数（其中最后一个数石num），
        这种num可能有很多种， 即for num in nums。
"""
class Solution:
    def combinationSum4(self, nums, target: int) -> int:
        # dp[i]表示i可以表示的组合数
        dp = [0] * (target + 1)
        dp[0] = 1  # 只能可能发生在target=nums[i]，因此为1（给出的是正数）
        for i in range(0, target+1):
            for num in nums:
                if i - num >= 0:
                    dp[i] += dp[i-num]
        return dp[target]

if __name__ == '__main__':
    nums = [1, 2, 3]
    target = 4
    solution = Solution()
    res = solution.combinationSum4(nums, target)
    print(res)
