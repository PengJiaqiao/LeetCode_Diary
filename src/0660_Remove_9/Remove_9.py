class Solution:
    def newInteger(self, n: int) -> int:
        res = []
        while n > 0:
            res.append(str(n % 9))
            n //= 9
        res.reverse()
        return int(''.join(res))
