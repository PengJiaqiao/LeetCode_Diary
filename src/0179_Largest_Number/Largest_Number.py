class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        import functools
        def cmp(a,b):
            if a+b > b+a: return -1
            else: return  1

        s = ''.join(sorted(map(str, nums), key = functools.cmp_to_key(cmp)))
        return '0' if s[0] == '0' else s
