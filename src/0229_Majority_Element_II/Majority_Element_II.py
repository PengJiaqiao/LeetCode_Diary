class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        m = n = cm = cn = 0
        for num in nums:
            if num == m: cm += 1
            elif num == n: cn += 1
            elif cm == 0:
                m = num
                cm = 1
            elif cn == 0:
                n = num
                cn = 1
            else:
                cm -= 1
                cn -= 1
        cm = cn = 0
        for num in nums:
            if num == m:
                cm += 1
            elif num == n:
                cn += 1
        res = []
        if cm > len(nums) / 3:
            res.append(m)
        if cn > len(nums) / 3:
            res.append(n)
        return res
