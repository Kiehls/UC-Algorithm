class Solution(object):
    def countBits(self, num):
        _bit = []
        for var in range(num + 1):
            bits = 0
            while var != 0:
                if var & 1 == 1:
                    bits += 1
                var = var >> 1
            _bit.append(bits)
        return _bit

Solution.countBits(Solution, 8)
