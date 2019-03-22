class Solution:
    def isConvex(self, points: List[List[int]]) -> bool: # use cross product
        def direction(a, b, c):
            return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0]-a[0])
        
        direct = 0
        for i in range(len(points)):
            cur_direct = direction(points[i-2], points[i-1], points[i])
            if cur_direct == 0: continue
            if not direct: direct = cur_direct
            else:
                if direct*cur_direct < 0: return False
        return True
