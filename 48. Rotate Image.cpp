class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {  //i表示从外到内的第几圈
            for (int j = i; j < n - 1 - i; ++j) {  //j表示第i圈的第一条边的第几个,这里要多减一，不然对角会多转一圈
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];  //左下->左上
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];  //右下->左下
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];  //右上->右下
                matrix[j][n - 1 - i] = temp;  //左上->右上
            }
        }
    }
};
