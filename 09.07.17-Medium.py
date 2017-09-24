class Solution(object):
    def complexNumberMultiply(self, a, b):
        _aint, _afalse = a.split('+')
        _afalse = int(_afalse.split('i')[0])
        _bint, _bfalse = b.split('+')
        _bfalse = int(_bfalse.split('i')[0])

        real = int(_aint) * int(_bint) + _afalse * _bfalse * -1
        fake = int(_aint) * _bfalse + int(_bint) * _afalse

        return "{}+{}i".format(real, fake)