class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        for(const int& num:nums){
            numsSet.insert(num);
        }
        int maxLength = 0;
        for(const int& num:numsSet){
            if(!numsSet.count(num - 1)){
                int currNum = num;
                int currLength = 1;
                while(numsSet.count(currNum + 1)){
                    ++currNum;
                    ++currLength;
                }
                maxLength = max(currLength, maxLength);
            }
        }
        return maxLength;
    }
};
