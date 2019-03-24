class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        return list((Counter(nums1) & Counter(nums2)).elements())
