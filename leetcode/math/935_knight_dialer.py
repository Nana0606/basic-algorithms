# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2018/11/6 15:17
import numpy as np

def knightDialer(N):
    """
    :type N: int，需要走多少步
    :rtype: int
    """
    mod = 10**9 + 7
    if N==1:
        return 10
    M = np.matrix([
        [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
        [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 0, 0, 0, 0]
    ])
    res, N = 1, N -1
    while N > 0:
        if N % 2:
            res = np.dot(res, M) % mod
        M = np.dot(M, M) % mod
        N = int(N/2)
    return int(np.sum(res)) % mod

if __name__ == '__main__':
    res = knightDialer(161)
    print("res is::", res)
