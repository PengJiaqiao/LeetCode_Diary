class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        carry = 0
        for i in range(len(A) - 1, -1, -1):
            last = K % 10
            K = K // 10
            tmp = last + A[i] + carry
            A[i] = tmp % 10
            carry = tmp // 10
        while K:
            last = K % 10
            K = K // 10
            tmp = last + carry
            carry = tmp // 10
            A.insert(0, tmp % 10)
        if carry:
            A.insert(0, carry)
        return A
