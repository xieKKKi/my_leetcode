class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int pos = digits.size() - 1; pos>=0; --pos){
            if(++digits[pos] < 10)
                break;
            else
                digits[pos] %= 10;  //留下个位，进位
            if(pos == 0){
                digits.emplace(digits.begin(), 1);  // 最前面插入1
                break;
            }
        }
        return digits;
    }
};
