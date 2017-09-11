class Solution(object):
    def findDuplicates(self, nums):
        duplicate = []
        for x in nums:
            if nums[abs(x) - 1] < 0:
                duplicate.append(abs(x))
            else:
                nums[abs(x) - 1] *= -1

        return duplicate
