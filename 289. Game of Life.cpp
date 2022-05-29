class Solution {
public:
    inline int countNeighbors(vector<vector<int>>& board, int i, int j){
        int result = 0;
        if(i-1 >= 0 && board[i-1][j] > 0)  ++result;
        if(i+1 < board.size() && board[i+1][j] > 0) ++result;
        if(j-1 >= 0 && board[i][j-1] > 0)   ++result;
        if(j+1 < board[0].size() && board[i][j+1] > 0) ++result;
        if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] > 0)  ++result;
        if(i-1 >= 0 && j+1 < board[0].size() && board[i-1][j+1] > 0) ++result;
        if(i+1 < board.size() && j-1 >= 0 && board[i+1][j-1] > 0) ++result;
        if(i+1 < board.size() && j+1 < board[0].size() && board[i+1][j+1] > 0)   ++result;
        
        return result;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] > 0){  // 活细胞
                    switch(countNeighbors(board, i, j)){
                    case 2:
                    case 3:
                        break;
                    default:
                        board[i][j] = 2; // 2表示活细胞下一轮死亡
                        break;
                    }
                }
                else{  // 死细胞
                    if(countNeighbors(board, i, j) == 3)
                        board[i][j] = -1; // -1表示死细胞下一轮复活
                }
            }
        }
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j] == -1)
                    board[i][j] = 1;
            }
        }
    }
};
