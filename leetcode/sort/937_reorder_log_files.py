# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2018/11/11 10:40

class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        res_digit = []
        res_word = {}
        res_ordered_word = []
        for i in range(0, len(logs)):
            current = logs[i]
            if(self.isDigits(current)):
                res_digit.append(current)
            else:
                new_current = current[current.find(" ") + 1:] + " " + current[0: current.find(" ")+1]
                res_word[new_current] = current
        for key in sorted(res_word.keys()):
            res_ordered_word.append(res_word.get(key))
        return  res_ordered_word + res_digit

    def isDigits(self, str):
        vecs = str.split(" ")
        if vecs[1].isdigit():
            return True
        return False

if __name__ == '__main__':
    input = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    solution = Solution()
    outputs = solution.reorderLogFiles(input)
    print("outputs is::", outputs)