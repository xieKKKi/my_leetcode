class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int first_col = 0, first_row = 0;
        for(int i = 0; i < matrix.size(); ++i){  
            if(matrix[i][0] == 0){
                first_col = 1;
                break;
            }
        }
        for(int j = 0; j < matrix[0].size(); ++j){  
            if(matrix[0][j] == 0){
                first_row = 1;
                break;
            }
        }

        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){  
                    matrix[i][0] = 0;  // 用第一列来表示该行有没有0
                    matrix[0][j] = 0;  // 用第一行来表示该列有没有0
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i){  // 按第一列赋0, 注意这里要从1开始，防止第一行全部被赋0
            if(matrix[i][0] == 0){
                for(int j = 1; j < matrix[0].size(); ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); ++j){  // 按第一行赋0, 注意这里要从1开始，防止第一列全部被赋0
            if(matrix[0][j] == 0){
                for(int i = 1; i < matrix.size(); ++i){
                    matrix[i][j] = 0;
                }
            }
        }

        if(first_col){  
            for(int i = 0; i < matrix.size(); ++i){
                matrix[i][0] = 0;
            }
        }
        if(first_row){ 
            for(int j = 0; j < matrix[0].size(); ++j){
                matrix[0][j] = 0;
            }
        }
    }
};
