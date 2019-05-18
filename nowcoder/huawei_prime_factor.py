# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/9 20:21
import numpy as np

def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    for i in range(2, int(np.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


if __name__ == '__main__':
    number, res = int(input()), []
    for i in range(2, number//2+1):
        while number % i == 0:
            number /= i
            res.append(i)
    print(" ".join(map(str, res)) + " " if res else str(number) + " ")



