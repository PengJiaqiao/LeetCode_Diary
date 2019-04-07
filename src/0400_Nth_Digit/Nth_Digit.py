class Solution:
    def findNthDigit(self, n: int) -> int:
        tmp, i, num = 0, 1, 0
        while(True):
            if (tmp + 9 * i * 10**(i-1) >= n): break
            else:
                tmp += (9 * i * 10**(i -1))
                i += 1
        num = (n - tmp) / i 
        if num > int(num): num = int(num) + 1
        else: num = int(num)
        if num > 0:
            tmp += (num - 1) * i
        k = 10 ** (i - 1) + num - 1
        return int(str(k)[n - tmp - 1])
