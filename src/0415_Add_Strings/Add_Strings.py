class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        def _convertInter(num):
            return ord(num) - ord('0')

        num1, num2 = list(map(_convertInter, num1[::-1])), list(map(_convertInter, num2[::-1]))

        if len(num1) < len(num2):
            num1, num2 = num2, num1

        carry = 0
        for i in range(len(num1)):
            n = num2[i] if i < len(num2) else 0
            tmp = n + carry + num1[i]
            num1[i] = tmp % 10
            carry = tmp // 10

        if carry:
            num1.append(1)

        return ''.join(map(str, num1))[::-1]
