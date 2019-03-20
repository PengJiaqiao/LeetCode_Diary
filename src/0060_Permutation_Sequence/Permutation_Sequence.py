class Solution:
    def getPermutation(self, n: int, k: int) -> str:
         return self.getPermutationk(n, list(range(1,n+1)), k)
    
    def getPermutationk(self, n, s, k):
        if n == 1: return str(s[0])
        nn = self.fn(n-1)
        pos = (k-1) // nn
        k = k % nn
        #print "===", s, nn, pos, k
        return str(s.pop(pos))  + self.getPermutationk(n-1, s, k)
    
    
    def fn(self, n):
        if n == 1: return 1
        else: return n * self.fn(n-1)
