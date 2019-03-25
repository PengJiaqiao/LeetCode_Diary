class Solution:
    def reverse(self, x: int) -> int:
        negative = False
        if x < 0:
            negative = True
            x *= -1
        result = int(str(x)[::-1]) * -1 if negative else int(str(x)[::-1])

        if result not in range(-2**31, 2**31): return 0
        else: return result
