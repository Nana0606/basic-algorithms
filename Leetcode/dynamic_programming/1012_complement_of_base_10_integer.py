# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-17 10:31
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        erjinzhi = bin(N)[2:]   # 10->2
        new_str = ""
        for elem in erjinzhi:
            if elem == '0':
                new_str += '1'
            elif elem == '1':
                new_str += '0'
        return int(new_str, 2)


if __name__ == '__main__':
    solution = Solution()
    res= solution.bitwiseComplement(7)
    print(res)
