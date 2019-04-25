# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-25 10:37
"""
贪心算法：
类似于指针的概念，如果s[i]等于t[j]，则i和j都往后移，否则只有j往后移
"""
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        j = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        if i == len(s) and j <= len(t):  # 注意终止点条件i == len(s)
            return True
        else:
            return False


if __name__ == '__main__':
    s = "axc"
    t = "ahbgdc"
    solution = Solution()
    res = solution.isSubsequence(s, t)
    print(res)