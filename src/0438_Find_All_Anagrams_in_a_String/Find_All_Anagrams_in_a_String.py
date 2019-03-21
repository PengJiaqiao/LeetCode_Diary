class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res, dict = [], {}
        begin, end = 0, -1
        target = collections.Counter(p)
        while begin <= len(s) - len(p):
            if end + 1 < len(s) and end - begin + 1 < len(p):
                end += 1
                dict[s[end]] = dict.setdefault(s[end], 0) + 1
            else:
                dict[s[begin]] -= 1
                if dict[s[begin]] == 0: dict.pop(s[begin])
                begin += 1
            if end - begin + 1 == len(p) and dict == target: res.append(begin)
        return res
