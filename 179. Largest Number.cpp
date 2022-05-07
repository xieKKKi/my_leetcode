class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &x, int &y){  // 自定义排序方式
            long lenx = 10, leny = 10;  // 不用long会溢出
            while(lenx <= x) lenx *= 10;
            while(leny <= y) leny *= 10;
            return x * leny + y > y * lenx + x;  // 使用 >= 会报错？？？，测试用例：[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        });

        if(nums[0] == 0)
            return "0";

        string result = "";
        for(int num:nums){
            result += to_string(num);
        }
        return result;
    }
};
