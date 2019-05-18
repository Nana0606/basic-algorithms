# python3
# -*- coding: utf-8 -*-
# @Author  : lina
# @Time    : 2019-03-24 17:35
"""
思路：
Step1：先使用二分查找求出最小数字的下标，这表示翻转的折点
Step2：基于此折点我们可以在原升序操作上进行二分查找（只是需要注意，比较的时候，元升序序列的nums[mid]对应现在的nums[(mid+rotated)%N]）
"""

class Solution:
    def search(self, nums, target: int) -> int:
        # 首先使用二分查找找到最小的下标
        N = len(nums)
        low = 0
        high = N - 1
        while low < high:
            mid = int((low + high) / 2)
            if nums[mid] > nums[high]:    # 如果是正常的升序，则nums[mid] < nums[high]
                low = mid + 1
            else:
                high = mid
        # 当终止的时候low=high便是最小的下标值，下面是正常的二分查找的方法，注意有real_mid = (mid + rotated) % N
        rotated = low   # 出现转折点的位置
        low = 0  # low，high表示对正常的升序序列操作下标，即不是输入的下标，是将输入转为升序之后的下标
        high = N -1
        while low<=high:
            mid = int((low + high) /2)
            real_mid = (mid + rotated) % N
            if nums[real_mid] == target:   # 正常应该是和nums[mid]比较，但是因为正常的nums[mid]等于现在rotated后的nums[real_mid]
                return real_mid
            if nums[real_mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1

if __name__ == '__main__':
    nums = [4, 5, 6, 7, 0, 1, 2]
    target = 0
    solution = Solution()
    res = solution.search(nums, target)
    print(res)
