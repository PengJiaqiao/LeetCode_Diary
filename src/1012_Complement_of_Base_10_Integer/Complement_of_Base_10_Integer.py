class Solution:
    def bitwiseComplement(self, N: int) -> int:
        tmp = 1
        while tmp < N: 
            tmp <<= 1
            tmp += 1
        return tmp - N
