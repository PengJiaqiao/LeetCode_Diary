class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        dict, count = collections.defaultdict(int), 0
        for i in time:
            count += dict[(60-i%60)%60]
            dict[i%60] += 1
        return count
