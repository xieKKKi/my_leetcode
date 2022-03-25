class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  //先排序，把左端点较小的区间排到左边
        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i=1; i<intervals.size(); ++i){
            if(intervals[i][0] > end){  // 无交集
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else{
                if(intervals[i][1] > end)  //有可能被包含
                    end = intervals[i][1];
            }
        }
        result.push_back({start, end});
        return result;
    }
};
