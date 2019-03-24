class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        str_list = str.split(' ')
        return len(str_list) == len(pattern) and len(set(zip(str_list, pattern))) == len(set(pattern)) == len(set(str_list))
