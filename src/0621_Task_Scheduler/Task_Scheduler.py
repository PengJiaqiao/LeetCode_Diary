class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        val = list(collections.Counter(tasks).values())
        maxv = max(val)
        cnt = val.count(maxv)
        return max(len(tasks), (maxv-1) * (n+1) + cnt)
