class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        stone = collections.Counter(S)
        count = 0
        for letter, val in stone.items():
            if letter in J: count += val
        return count
