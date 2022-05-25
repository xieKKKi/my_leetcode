class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        for(int i=1;i<nums.size();++i){  // answer[i]是位置i左边所有数的乘积
            answer[i] = answer[i-1] * nums[i-1];
        }
        int rMultiply = 1;  // 右侧所有元素乘积
        for(int i=nums.size()-1;i>=0;--i){
            answer[i] = answer[i] * rMultiply;
            rMultiply *= nums[i]; 
        }
        return answer;
    }
};
