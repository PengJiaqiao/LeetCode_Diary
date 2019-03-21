class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        dict = {}
        begin, end = 0, len(s1)-1
        target = collections.Counter(s1)
        for i in s2[0:len(s1)]: dict[i] = dict.setdefault(i, 0) + 1
        while begin < len(s2) - len(s1):
            if dict == target: return True
            end += 1
            dict[s2[end]] = dict.setdefault(s2[end], 0) + 1
            dict[s2[begin]] -= 1
            if dict[s2[begin]] == 0: dict.pop(s2[begin])
            begin += 1
        return dict == target
