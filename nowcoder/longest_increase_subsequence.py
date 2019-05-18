# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/17 10:02
class AscentSequence:
    def findLongest(self, A, n):
        # write code here
        max = 0
        increase = []
        increase.append(1)
        for i in range(1, n):
            increase.append(1)
            for j in range(i-1, -1, -1):
                if A[i] > A[j] and increase[i] < increase[j] + 1:
                    increase[i] = increase[j] + 1
            if max < increase[i]:
                max = increase[i]
        return max

if __name__ == '__main__':
    A = [2, 1, 4, 3, 1, 5, 6]
    n = 7
    temp = AscentSequence()
    max = temp.findLongest( A, n)
    print(max)