class Solution(object):
    def findBottomLeftValue(self, root):
        self.max = -1
        self.val = -1
        self.calculateDepth(root, 0)
        return self.val

    def calculateDepth(self, root, depth):
        if not root:
            return
        if self.max < depth:
            self.max = depth
            self.val = root.val

        left = self.calculateDepth(root.left, depth + 1)
        right = self.calculateDepth(root.right, depth + 1)