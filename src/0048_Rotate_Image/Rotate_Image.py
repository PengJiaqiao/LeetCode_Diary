class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(0, n//2):
            for j in range(0, n-1-2*i):
                tmp = matrix[i][i+j]
                matrix[i][i+j] = matrix[n-1-i-j][i]
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j]
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i]
                matrix[i+j][n-1-i] = tmp
