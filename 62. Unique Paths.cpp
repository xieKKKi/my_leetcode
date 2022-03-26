class Solution {
public:
    //总共移动m+n-2次，其中有m-1次向下移动，选择这m-1次，计算组合数
    int uniquePaths(int m, int n) {
        long result = 1;
        for(int i = 2; i <= m; ++i){  //注意此处从小到大，不然会出现小数
            result = result * (i + n - 2) / (i - 1);  //注意此处先×后/，不然会出现小数
        }
        return result;
    }
};
