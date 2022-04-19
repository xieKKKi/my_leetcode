class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])
        def dfs(i ,j):
            if i <= 0 or i >= m-1 or j <= 0 or j >= n-1:
                return
            if(board[i][j] != 'O'):
                return
            board[i][j] = '#'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

        for i in range(m):
            if board[i][0] == 'O':
                board[i][0] = '#'
                dfs(i, 1)
            if board[i][n-1] == 'O':
                board[i][n-1] = '#'
                dfs(i, n-2)
        for i in range(n):
            if board[0][i] == 'O':
                board[0][i] = '#'
                dfs(1, i)
            if board[m-1][i] == 'O':
                board[m-1][i] = '#'
                dfs(m-2, i)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'
    
