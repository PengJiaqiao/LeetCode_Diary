class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([c  *freq for c, freq in collections.Counter(s).most_common()])
