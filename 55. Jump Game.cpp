class Solution {
public:
     bool canJump(vector<int>& nums) {
        int furthest = nums[0];  //存储能到达的最远距离
        for(int i=1; i<nums.size(); ++i){  //也要从小到大遍历，避免遗漏
            if(i > furthest)  // 已经超过最远范围了
                return false;
            if(nums[i] + i > furthest)
                furthest = nums[i] + i;
            if(furthest >= nums.size()-1)
                return true;
        }
        if(furthest >= nums.size()-1)
            return true;
        return false;
    }
    // 这个方法很慢
    // bool canJump(vector<int>& nums, int pos){
    //     if(pos == nums.size()-1)    return true;
    //     else if(pos >= nums.size() || nums[pos] <= 0)  return false;
        
    //     for(int i = nums[pos]; i > 0; --i){  //先跳远的，0不跳
    //         if(canJump(nums, pos + i))  
    //             return true;
    //         else if(pos + i < nums.size())
    //             nums[pos + i] = 0;
    //     }
    //     nums[pos] = 0;
    //     return false;
    // }
    // bool canJump(vector<int>& nums) {
    //     return canJump(nums, 0);
    // }
};
