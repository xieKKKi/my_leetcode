class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp_min(nums.size(), nums[0]);
        vector<int> dp_max(nums.size(), nums[nums.size()-1]);
        for(int i=1;i<nums.size();++i){
            dp_min[i] = nums[i] < dp_min[i-1] ? nums[i] : dp_min[i-1];
        }
        for(int i=nums.size()-2;i>=0;--i){
            dp_max[i] = nums[i] > dp_max[i+1] ? nums[i] : dp_max[i+1];
        }
        for(int i=0;i<nums.size()-1;++i){
            if(dp_min[i] < nums[i] && nums[i] < dp_max[i])
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0], second = INT_MAX;
        for(int i=1;i<nums.size();++i){
            if(nums[i] > second)
                return true;
            else if(nums[i] > first)
                second = nums[i];
            else
                first = nums[i];
        }
        return false;
    }
};
