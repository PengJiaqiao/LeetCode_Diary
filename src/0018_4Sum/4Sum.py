class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        dict = {}
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                sum = nums[i] + nums[j]
                if sum in dict: dict[sum].add((i,j))
                else: dict[sum] = {(i,j)}
        result = set()
        for key, first_indices in list(dict.items()):
            second_indices = dict.get(target - key)
            if second_indices:
                for p, q in second_indices:
                    for i, j in first_indices:
                        # Not reusing the same number twice
                        if not ({i, j} & {p, q}):
                            indices = tuple(sorted(nums[x] for x in (i, j, p, q)))
                            result.add(indices)
                dict.pop(target- key)
        return [list(i) for i in result]
