class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def is_sub(parent, child):
            for i, v in child.items():
                if i not in parent:
                    return False
                elif child[i] > parent[i]:
                    return False
            return True

        dict, res = {}, s + t
        target = collections.Counter(t)
        begin, end = 0, - 1
        while 1:
            if is_sub(dict, target):
                while s[begin] not in target: begin += 1
                res = s[begin:end+1] if end - begin + 1 < len(res) else res
                dict[s[begin]] -= 1
                if dict[s[begin]] == 0: dict.pop(s[begin])
                begin += 1
            elif end + 1 < len(s):
                end += 1
                if s[end] in target: dict[s[end]] = dict.setdefault(s[end], 0) + 1
            else: break
        return res if len(res) <= len(s) else ""
