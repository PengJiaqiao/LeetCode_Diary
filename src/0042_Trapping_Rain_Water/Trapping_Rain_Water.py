# class Solution:
#     def trap(self, height: List[int]) -> int:
#         if len(height) < 3: return 0
#         pre, idx, tmp, res = 0, 0, 0, 0
#         if height[0] > height[1]: pre, idx, tmp = height[0], 1, height[0] - height[1]
#         else: pre, idx = height[1], 2
#
#         for i in range(2, len(height)):
#             if height[i] >= pre:
#                 pre = height[i]
#                 idx = i + 1
#                 res += tmp
#                 tmp = 0
#                 continue
#             tmp += pre - height[i]
#             if height[i] > height[i-1]:
#                 add = 0
#                 for j in range(idx, i):
#                     if height[j] < height[i]:
#                         add += height[i] - height[j]
#                         height[j] = height[i]
#                 res += add
#                 tmp -= add
#         return res

    lenh = len(height)
        al = h1 = h2 = 0
        for i in range(lenh):
            h1,h2 = max(h1,height[i]),max(h2,height[-1-i])
            al += h1 + h2
        return al - sum(height) - h1 * lenh
