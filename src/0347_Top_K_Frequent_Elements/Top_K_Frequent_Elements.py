class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        return [c[0] for c in Counter(nums).most_common(k)]
