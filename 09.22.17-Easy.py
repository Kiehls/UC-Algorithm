# class Solution(object): --- Time Limit Exceeded
#     def findDisappearedNumbers(self, nums):
#         _list = [x for x in range(1, len(nums) + 1)]
#         for num in nums:
#             if num in _list:
#                 _list.remove(num)
#
#         return _list

class Solution(object):
    def findDisappearedNumbers(self, nums):
        for idx in xrange(len(nums)):
            tmp = abs(nums[idx]) - 1
            nums[tmp] = abs(nums[tmp]) * -1
        return [x + 1 for x in range(len(nums)) if nums[x] > 0]