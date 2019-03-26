class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res, tmp = [], ""
        self.dfs(res, 0, 0, n, tmp)
        return res
    
    def dfs(self, res: List[str], left: int, right: int, n: int, tmp: str):
        if left == right == n: res.append(tmp)
        elif left < n:
            tmp_ = tmp + "("
            self.dfs(res, left+1, right, n, tmp_)
            for i in range(left+1-right):
                tmp_ += ")"
                self.dfs(res, left+1, right+i+1, n, tmp_)
