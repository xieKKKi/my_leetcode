class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos2 = nums.size() - 1;  // 0和2已经排好的位置
        while(pos0 < nums.size() - 1 && nums[pos0] == 0)
            ++pos0;
        while(pos2 > 0 && nums[pos2] == 2)
            --pos2; 
        if(pos0 == nums.size() - 1 || pos2 == 0)
            return;
        
        for(int i = pos0; i <= pos2;){
            if(nums[i] == 0){
                swap(nums[i], nums[pos0]);  //把0置于pos0位置
                ++pos0;
                if(pos0 > i)  // 有可能超过的
                    i = pos0;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[pos2]);  //把2置于pos2位置
                --pos2;
            }
            else{
                ++i;
            }
        }
    }
};
