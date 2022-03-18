class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> nums, int pos){  //全排列用backtrack
        if(pos == nums.size()-1){
            result.emplace_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();++i){
            swap(nums[pos], nums[i]);
            backtrack(nums, pos+1);
            swap(nums[pos], nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        backtrack(nums, 0);
        return result;
    }
};
