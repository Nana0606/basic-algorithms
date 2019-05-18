# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-21 08:51


"""
swap[i]表示如果移动A[i]和B[i]使得A[0,...i]和B[0,...i]是上升子序列，需要的交换次数
not_swap[i]表示如果不移动A[i]和B[i]使得A[0,...i]和B[0,...i]是上升子序列，需要的交换次数
其主要思想：
①初始化：因为最后是需要取最小的，所以直接初始化为最大值。
②swap[0]=1表示如果交换A[0]和B[0]，则需要1次的交换次数
③A[i-1] < A[i] and B[i-1] < B[i]：说明可以选择不交换，此时not_swap[i] = not_swap[i-1]；也可以选择交换（有时候为了后面有序，必须考虑全局，也有可能需要交换的情况），swap[i] = swap[i-1] + 1
④A[i - 1] < B[i] and B[i- 1] < A[i]，在这种情况下，如果A[i-1]和B[i-1]已经交换，则已经有序，A[i]和B[i]不需要交换；如果A[i-1]和B[i-1]不交换，则A[i]和B[i]可能交换
"""

class Solution:
    def minSwap(self, A, B) -> int:
        N = len(A)
        swap = [N] * N
        not_swap = [N] * N
        swap[0], not_swap[0] = 1, 0
        for i in range(1, N):
            if A[i-1] < A[i] and B[i-1] < B[i]:
                not_swap[i] = not_swap[i-1]
                swap[i] = swap[i-1] + 1
            if A[i - 1] < B[i] and B[i- 1] < A[i]:
                not_swap[i] = min(not_swap[i], swap[i-1])    # if A[i-1] and B[i-1] are swaped, we don't need to swap A[i] and B[i]
                swap[i] = min(swap[i], not_swap[i-1] + 1)    # if A[i - 1] and B[i-1] are not swaped, we need to swap A[i] and B[i]， +1是指前面的不交换，但是A[i]和B[i]交换
        return min(swap[-1], not_swap[-1])


if __name__ == '__main__':
    A = [1, 3, 5, 4]
    B = [1, 2, 3, 7]
    solution = Solution()
    res = solution.minSwap(A, B)
    print(res)