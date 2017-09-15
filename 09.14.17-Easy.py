class Solution(object):
    def reverseWords(self, s):
        split = s.split(' ')

        _str = ''
        for sub in split:
            _str += ''.join(reversed(sub))
            _str += ' '

        return _str.rstrip()