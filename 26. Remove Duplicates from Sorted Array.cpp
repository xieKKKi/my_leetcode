class Solution {
public:
    int removeDuplicates(vector<int>& nums) {  //vector erase函数会遍历容器，不要使用
        if(nums.size() <= 1)
            return nums.size();
            
        int slow = 0, fast = 1;  //快慢指针
        while(fast < nums.size()){
            if(nums[fast] != nums[slow]){
                nums[++slow] = nums[fast];
            }
            ++fast;
        }
        return slow + 1;
    }
};
