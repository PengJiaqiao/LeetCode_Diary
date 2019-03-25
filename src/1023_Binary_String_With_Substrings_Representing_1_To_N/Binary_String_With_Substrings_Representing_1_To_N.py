class Solution:
    def queryString(self, S: str, N: int) -> bool:
        for i in range(1, N+1):
            tmp = bin(i)[2:]
            if tmp not in S: return False
        return True
