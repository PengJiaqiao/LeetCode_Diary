class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] < 9:
            digits[-1] += 1
        else:
            digits[-1] = 0
            carry = 1
            i = len(digits) - 2
            while i >= 0 and carry:
                tmp = digits[i] + carry
                carry = tmp // 10
                digits[i] = tmp % 10
                i -= 1
            if carry:
                digits.insert(0, 1)
        return digits
