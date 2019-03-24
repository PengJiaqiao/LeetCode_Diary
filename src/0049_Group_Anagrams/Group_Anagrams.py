class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import Counter, defaultdict
        dict = defaultdict(list)
        for str in strs:
            dict[frozenset((k, v) for k, v in Counter(str).items())].append(str)
        return list(dict.value())
    
    '''
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mem = {} 
        for s in strs:
            std = ''.join(sorted(s))
            if std in mem:
                mem[std] += [s]
            else:
                mem[std] = [s]
        return list(mem.values())
    '''
