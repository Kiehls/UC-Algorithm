class Solution(object):
    def trimBST(self, root, L, R):
        if not root:
            return None

        node = TreeNode(root.val)
        node.left = self.trimBST(root.left, L, R)
        node.right = self.trimBST(root.right, L, R)

        if node.val < L:
            return node.right
        if node.val > R:
            return node.left

        return node