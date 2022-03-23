class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> result;
        //这里定义上下左右边界会让代码更加清晰，只定义i，j会让思路很凌乱
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1; 
        while(true)
        {
            for(int i = left; i <= right; ++i) result.emplace_back(matrix[up][i]); //向右移动直到最右
            if(++ up > down) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = up; i <= down; ++i) result.emplace_back(matrix[i][right]); //向下
            if(-- right < left) break; //重新设定右边界
            for(int i = right; i >= left; --i) result.emplace_back(matrix[down][i]); //向左
            if(-- down < up) break; //重新设定下边界
            for(int i = down; i >= up; --i) result.emplace_back(matrix[i][left]); //向上
            if(++ left > right) break; //重新设定左边界
        }
        return result;
    }
};
