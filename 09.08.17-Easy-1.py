class Solution(object):
    def arrayPairSum(self, nums):
        sortedNums = sorted(nums)
        _list = [sortedNums[idx] for idx in range(0, len(nums), 2)]

        _sum = 0
        for val in _list:
            _sum += val

        return _sum
