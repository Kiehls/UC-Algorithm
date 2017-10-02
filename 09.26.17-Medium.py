class Solution(object):
    def largestValues(self, root):
        self.largest = {}
        self.findLargest(root, 0)
        return self.largest.values()

    def findLargest(self, root, depth):
        if not root:
            return

        if depth not in self.largest:
            self.largest[depth] = root.val
        if root.val > self.largest[depth]:
            self.largest[depth] = root.val

        self.findLargest(root.left, depth + 1)
        self.findLargest(root.right, depth + 1)