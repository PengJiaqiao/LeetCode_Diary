class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0: return '0'
        res, remaining = "", N
        while remaining != 0:
            minus = 1 if len(res) % 2 == 0 else -1
            if remaining % 2 == 1:
                res += '1'
                remaining -= minus * 1
            else:
                res += '0'
            remaining = remaining / 2
        return res[::-1]
