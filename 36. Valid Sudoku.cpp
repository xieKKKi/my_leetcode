class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //注意这里的记录数组不要使用vector定义，vector定义在栈上，二维以上vector的元素不是连续存放的，会导致运行很慢
        bool row[9][9] = {0};  //记录行中的数字是否已经出现
        bool col[9][9] = {0};  //记录列
        bool block[9][9] = {0};  //记录九宫格

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';  //这里-1不要-0，不然会越界
                    int blockIndex = i/3 + (j/3)*3; 
                    if(row[i][num] || col[j][num] || block[blockIndex][num])
                        return false;
                    row[i][num] = true; 
                    col[j][num] = true; 
                    block[blockIndex][num] = true; 
                }
            }
        }
        return true;
    }
};
// class Solution {
// public:
//     bool hasRepeatedNum(const vector<char> nums){  //使用const更好
//         unordered_set<char> s;
//         for(char ch:nums){
//             if('0' <= ch && ch <= '9'){
//                 if(s.find(ch) != s.end())
//                     return true;
//                 s.insert(ch);
//             }
//         }
//         return false;
//     }
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i=0;i<9;++i){  //检查行
//             if(hasRepeatedNum(board[i]))
//                 return false;
//         }
//         for(int i=0;i<9;++i){  //检查列
//             if(hasRepeatedNum({board[0][i], board[1][i], board[2][i], board[3][i], board[4][i], board[5][i], board[6][i], board[7][i], board[8][i]}))
//                 return false;
//         }
//         for(int i=0;i<3;++i){  //检查九宫格
//             for(int j=0;j<3;++j){
//                 if(hasRepeatedNum({board[3*i][3*j], board[3*i][3*j+1], board[3*i][3*j+2], board[3*i+1][3*j], board[3*i+1][3*j+1], board[3*i+1][3*j+2], board[3*i+2][3*j], board[3*i+2][3*j+1], board[3*i+2][3*j+2], }))
//                 return false;
//             }
//         }
//         return true;
//     }
// };
