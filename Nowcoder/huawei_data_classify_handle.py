# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019/1/18 8:44
if __name__ == '__main__':
    while True:
        try:
            sequence_temp_i = [elem for elem in input().split(' ') if elem != '']
            sequence_i = sequence_temp_i[1:]
            sequence_temp_r = [int(elem) for elem in input().split(' ') if elem != '']
            sequence_r = list(set(sequence_temp_r[1:]))
            sequence_r_sort = sorted(sequence_r)
            result = []
            for i in range(0, len(sequence_r_sort)):
                current = str(sequence_r_sort[i])
                counter = 0
                result.append(current)
                current_temp = []
                for idx, value in enumerate(sequence_i):
                    if current in value:
                        current_temp.append(str(idx))
                        current_temp.append(value)
                        counter += 1
                if counter == 0:
                    result = result[:-1]
                else:
                    result.append(str(counter))
                    result = result + current_temp
            print(str(len(result)), end=' ')
            print(' '.join(result))
        except:
            break


