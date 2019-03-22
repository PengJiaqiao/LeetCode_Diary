class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        m, n = len(picture), len(picture[0])
        row, col = [0]*m, [0]*n

        for i in range(0, m):
            for j in range(0, n):
                if picture[i][j] == 'B':
                    row[i] += 1
                    col[j] += 1
        row_count = col_count = 0
        for i in row: row_count += 1 if i == 1 else 0
        for i in col: col_count += 1 if i == 1 else 0
        return min(row_count, col_count)
