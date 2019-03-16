# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2018/11/18 11:02

class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
    pass

    def isSorted(self, element):
        i = 0
        j = 0
        flag = 1  # 判断是否为升序
        # 判断是否为升序
        for i in range(0, len(element) - 1):
            if element[i] > element[i+1]:
                flag = 0   # 不是升序
                break
            if i == len(element) - 2 and  element[i] < element[i+1]:  # 是升序
                return True
        for j in range(0, len(element) - 1):
            if element[j] < element[j + 1]:   # 不是降序
                if flag ==0 :   # 不是升序且不是降序
                    return False
                else:
                    break
            if j == len(element) - 2 and element[j] > element[j + 1]:  # 是升序
                return True
        return False


if __name__ == '__main__':
    solution = Solution()
    # A = {"cba", "daf", "ghi"}
    # res = solution.minDeletionSize(A)
    res = solution.isSorted("bcd")
    print("res is::", res)
