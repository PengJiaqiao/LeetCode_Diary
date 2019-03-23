class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        prev, prev_count = None, 0
        starts = collections.deque()
        for t, grp in itertools.groupby(nums):
            count = len(list(grp))
            if prev is not None and t - prev != 1:
                for _ in range(prev_count):
                    if prev < starts.popleft() + 2:
                        return False
                prev, prev_count = None, 0

            if prev is None or t - prev == 1:
                if count > prev_count:
                    for _ in range(count - prev_count):
                        starts.append(t)
                elif count < prev_count:
                    for _ in range(prev_count - count):
                        if t-1 < starts.popleft() + 2:
                            return False

            prev, prev_count = t, count

        return all(nums[-1] >= x+2 for x in starts)

# class Solution:
#     def isPossible(self, nums: List[int]) -> bool:
#         counter = [list(item) for item in collections.Counter(nums).items()]
#         dict = {}
#         for i in range(0, len(counter)):
#             while counter[i][1]:
#                 if counter[i][0] in dict:
#                     dict[counter[i][0]] -= 1
#                     if dict[counter[i][0]] == 0: del dict[counter[i][0]]
#                     dict[counter[i][0]+1] = dict.setdefault(counter[i][0]+1, 0) + 1
#                     counter[i][1] -= 1
#                 elif i < len(counter)-2 and counter[i+1][0] == counter[i][0] + 1 and counter[i+1][1] and counter[i+2][0] == counter[i][0] + 2 and counter[i+2][1]:
#                     dict[counter[i][0]+3] = dict.setdefault(counter[i][0]+3, 0) + 1
#                     counter[i][1] -= 1
#                     counter[i+1][1] -= 1
#                     counter[i+2][1] -= 1
#                 else: return False
#         return True
