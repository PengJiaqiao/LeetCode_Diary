class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        res = 0
        for p in points:
            cmap = {}
            for q in points:
                f = p[0]-q[0]
                s = p[1]-q[1]
                cmap[f*f + s*s] = cmap.setdefault(f*f + s*s, 0) + 1
            for k in cmap:
                res += cmap[k] * (cmap[k] -1)
        return res
