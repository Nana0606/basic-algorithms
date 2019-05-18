# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-25 11:07
"""
算法思路：
若已经知道n-1的走法和n-2的走法，则n的走法种数是n-1的解法种数和n-2的解法种数之和
①从n-1的种数到n的种数，我们可以在第n步走1步
②从n-2的种数到n的种数，我们可以在第n步走2步
对于n==3：  2_bef    1_bef   all_ways
             1        2       3          4         5
对于n==4：          2_bef    1_bef      all_ways
"""

class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2
        first_before = 2    # 对于3而言，1步之前是2，有2种走法
        second_before = 1   # 对于3而言，2步之前是1，只有1种走法
        all_ways = 0
        for i in range(3, n + 1):  # 更新机制示意图，详看上面解释
            all_ways = first_before + second_before
            second_before = first_before
            first_before = all_ways
        return all_ways

if __name__ == '__main__':
    n = 4
    solution = Solution()
    res = solution.climbStairs(n)
    print(res)