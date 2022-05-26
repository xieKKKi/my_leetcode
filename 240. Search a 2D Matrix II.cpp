class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(), i = rows-1, j = 0;  //从左下开始z字形查找
        while(i >= 0 && j < cols){
            if(matrix[i][j] == target)  return true;
            else if(matrix[i][j] > target)  --i;
            else    ++j;
        }
        return false;
    }
};
