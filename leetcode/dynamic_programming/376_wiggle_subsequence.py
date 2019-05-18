# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-20 08:59

"""
AC: 本题看起来和最长上升子串比较类似，但是存在几个比较容易错的问题
①对于长度为2的元素需要特殊处理
②对于有连续数字相等的情况需要特殊处理
"""

class Solution:
    def wiggleMaxLength(self, nums) -> int:
        # wiggle[i]表示从num[0,...i]
        wiggle = [0] * len(nums)
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return 1
        elif len(nums) == 2:
            if nums[0] == nums[1]:
                return 1
            else:
                return 2
        else:
            wiggle[0] = 1
            sign = [0] * len(nums)   # sign[i]表示wiggle[i+1]最后的符号，即nums[i+1]-nums[i]的符号
            sign[0] = nums[1] - nums[0]
            if sign[0] == 0:   # 对连续2个数字相等的需要特殊处理
                wiggle[1] = 1
            else:
                wiggle[1] = 2
            for i in range(2, len(nums)):
                max_cur = 1
                flag = 0  # 是否找到为更大的
                for j in range(i-1, -1, -1):
                    if (nums[i] - nums[j]) * sign[j-1] < 0 and max_cur < wiggle[j] + 1:
                        max_cur = wiggle[j] + 1
                        sign[i - 1] = nums[i] - nums[j]
                        flag = 1
                if flag == 0:
                    sign[i - 1] = nums[i] - nums[i-1]
                    if sign[i-1] !=0:
                        max_cur = 2
                wiggle[i] = max_cur
        return max(wiggle)

if __name__ == '__main__':
    nums = [1,17,5,10,13,15,10,5,16,8]
    solution = Solution()
    res = solution.wiggleMaxLength(nums)
    print(res)
