class Solution {
public:
    int search(vector<int>& nums, int target, int left, int right){
        if(nums[left] == target)
            return left;
        if(left >= right)
            return -1;
        
        int mid = (left+right) / 2;
        if(nums[mid] < target)
            return search(nums, target, mid+1, right);  //这里要+1防止区间重复
        else if(nums[mid] > target)
            return search(nums, target, left, mid);
        else
            return mid;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)  //考虑空数组，因为后面二分查找没有考虑
            return {-1, -1};

        vector<int> result;
        int pos = search(nums, target, 0, nums.size()-1);
        if(pos == -1){
            return {-1, -1};
        }
        else{
            int i = 0;
            while(pos+i-1 >= 0 && nums[pos+i-1] == target) --i;
            result.emplace_back(pos+i);
            i = 0;
            while(pos+i+1 < nums.size() && nums[pos+i+1] == target) ++i;
            result.emplace_back(pos+i);
        }
        return result;
    }
};
