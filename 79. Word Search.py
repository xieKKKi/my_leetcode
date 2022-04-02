class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def backtrack(i, j, k):  # i行j列，word中第k个字符
            if(i < 0 or i >= len(board) or j < 0 or j >= len(board[0])):  # 判断越界
                return False
            if((i, j) in visited):  # 判断是否访问过
                return False
            if(word[k] == board[i][j]):  # 相等
                if(k == len(word) - 1):  # 到最后了
                    return True
                else:
                    visited.add((i ,j))
                    if(backtrack(i+1, j, k+1) or backtrack(i-1, j, k+1) 
                        or backtrack(i, j-1, k+1) or backtrack(i, j+1, k+1)):
                        return True
                    visited.remove((i, j))  # 要记得移除
                    return False
            else:
                return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                visited = set()  # set存储访问过的位置
                if(backtrack(i, j, 0)):
                    return True
        return False
