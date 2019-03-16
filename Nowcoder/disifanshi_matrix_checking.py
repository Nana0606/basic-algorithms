# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-02-24 18:29

def checking(matrix, m, n, k):
    for i in range(0, int(m)):
        if k >= int(matrix[i][0]) and k <= int(matrix[i][n-1]):
            for j in range(0, n):
                if k == int(matrix[i][j]):
                    return True
                if k > int(matrix[i][j]):
                    continue
    return False

if __name__ == '__main__':
    [m,n] = input().split(' ')
    matrix = [[] for i in range(0, int(m))]
    for i in range(0, int(m)):
        n_elem_list = input().replace('\u200b\u200b', '').split(' ')
        matrix[i] = n_elem_list
    k = int(input())
    res = checking(matrix, int(m), int(n), k)
    print('true' if res == True else 'false')


