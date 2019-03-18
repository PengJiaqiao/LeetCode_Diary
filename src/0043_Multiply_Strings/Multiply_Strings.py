class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def _convertInter(num):
            return ord(num) - ord('0')
        num1_, num2_= 0, 0
        for num in num1:
            num1_ = num1_ * 10 + _convertInter(num)
        for num in num2:
            num2_ = num2_ * 10 + _convertInter(num)
        res = num1_ * num2_
        return str(res)
