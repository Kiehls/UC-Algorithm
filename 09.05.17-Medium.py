class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def constructMaximumBinaryTree(self, nums):
        if len(nums) == 0:
            return None

        _root = max(nums)
        _rootIdx = nums.index(_root)
        MBT = TreeNode(_root)

        left = nums[:_rootIdx]
        right = nums[_rootIdx + 1:]

        MBT.left = self.constructMaximumBinaryTree(left)
        MBT.right = self.constructMaximumBinaryTree(right)

        return MBT
