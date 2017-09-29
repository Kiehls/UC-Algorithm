class Solution:
    def averageOfLevels(self, root):
        self.value = {}
        self.averageTree(root, 0)

        return [sum(self.value[x]) / len(self.value[x]) for x in self.value]

    def averageTree(self, root, depth):
        if not root:
            return

        if depth not in self.value:
            self.value[depth] = [root.val]
        else:
            self.value[depth].append(root.val)

        self.averageTree(root.left, depth + 1)
        self.averageTree(root.right, depth + 1)
