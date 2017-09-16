class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        _max = temp = 0
        for num in nums:
            if num == 0:
                _max = max(temp, _max)
                temp = 0
                continue
            temp += num
        return _max if _max > temp else temp