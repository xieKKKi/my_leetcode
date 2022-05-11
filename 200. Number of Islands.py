class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def backtrack(i, j):
            if 0 <= i and i < len(grid) and 0 <= j and j < len(grid[0]):
                if grid[i][j] == '1':
                    grid[i][j] = '0'
                    backtrack(i-1, j)
                    backtrack(i, j-1)
                    backtrack(i+1, j)
                    backtrack(i, j+1)
        
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    backtrack(i, j)
                    count += 1
        return count
