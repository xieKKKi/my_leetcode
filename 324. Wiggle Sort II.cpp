class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());  // 反序
        vector<int> tmp(nums.begin(), nums.end());
        int mid = nums.size() / 2;  // 分成两部分，间隔插入
        for(int i=0;i<nums.size();++i){
            if(i % 2)
                nums[i] = tmp[i / 2];
            else
                nums[i] = tmp[mid + i / 2];
        }
    }
};
