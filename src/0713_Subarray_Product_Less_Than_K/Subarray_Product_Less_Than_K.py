class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        product = nums[0]
        count = length = 1 if product < k else 0
        for i in range(1, len(nums)):
            tmp = product * nums[i]
            if tmp < k:
                length += 1
                count += length
                product = tmp
            else:
                if nums[i] < k:
                    product = tmp
                    j = i - length
                    while product >= k:
                        product /= nums[j]
                        j += 1
                        length -= 1
                    length += 1
                    count += length
                else: 
                    product = 1
                    length = 0
        return count
