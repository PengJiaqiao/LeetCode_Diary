class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        res, window = [], sorted(nums[0:k])
        res.append(float(window[k//2] if k % 2 == 1 else (window[k//2] + window[k//2-1])/2))
        for i in range(k, len(nums)):
            begin, end, delete = 0, k - 1, nums[i-k]
            while begin < end:
                mid = (begin + end) // 2
                if window[mid] >= delete: end = mid
                else: begin = mid + 1
            del window[begin]
            begin, end, insert = 0, k - 2, nums[i]
            while begin < end:
                mid = (begin + end) // 2
                if window[mid] >= insert: end = mid
                else: begin = mid + 1
            if begin == k - 2 and insert > window[begin]: begin += 1
            window.insert(begin, insert)
            res.append(float(window[k//2] if k % 2 == 1 else (window[k//2] + window[k//2-1])/2))
        return res
