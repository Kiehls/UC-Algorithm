class Solution(object):
    def searchInsert(self, nums, target):
        if target in nums:
            return nums.index(target)
        if target < nums[0]:
            return 0

        _min = _max = 0
        for idx, var in enumerate(nums):
            if var < target:
                _min = idx + 1
        return _min