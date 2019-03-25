class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3 != 0: return False
        target = s // 3
        cur = count = 0
        for num in A:
            cur += num
            if cur == target:
                count += 1
                cur = 0
        return count == 3
