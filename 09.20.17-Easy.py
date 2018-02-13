# class Solution(object): --- Time Limit Exceeded
#     def maxSubArray(self, nums):
#         _maxSum = max_l_idx = max_r_idx = sys.maxint * -1
#         for idx in xrange(len(nums)):
#             for _idx in xrange(idx, len(nums)):
#                 if sum(nums[idx:_idx + 1]) > _maxSum:
#                     _maxSum = sum(nums[idx:_idx + 1])
#                     max_l_idx = idx
#                     max_r_idx = _idx
#         return _maxSum