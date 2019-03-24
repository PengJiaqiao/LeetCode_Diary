class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(s) == len(t) and len(set(zip((s[i], t[i]) for i in range(len(s))))) == len(set(s)) == len(set(t))
