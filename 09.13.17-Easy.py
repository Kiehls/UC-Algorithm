class Solution(object):
    def climbStairs(self, n):
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n == 3:
            return 3
        else:
            _list = [1, 2]
            for i in range(2, n):
                _list.append(_list[i - 1] + _list[i - 2])
            return _list[-1]