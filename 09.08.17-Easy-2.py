import numpy as np

class Solution(object):
    def matrixReshape(self, nums, r, c):
        row = len(nums)
        col = len(nums[0])

        if row * col != r * c:
            return nums

        return np.reshape(nums, (r, c)).tolist()