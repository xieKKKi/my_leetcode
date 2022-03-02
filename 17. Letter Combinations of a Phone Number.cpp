class Solution {
private:
    vector<string> result;
    string tmp = "";
    const vector<string> dic = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    /*
    * 全排列问题，用回溯法
    * digits 电话数字
    * tmp 当前正在排列的字符串
    * pos 当前对应数字位置
    */
    void backtrack(string &digits, int pos){  
        if(pos >= digits.length()){  //递归终止条件，数到了最后一位
            result.emplace_back(tmp);  //emplace_back比push_back更高效
            return;
        } 

        int num = digits[pos] - '2';  //当前对应数字，从2开始故要-2
        for(char ch:dic[num]){  //遍历当前数字对应的几个字母
            tmp.push_back(ch);
            backtrack(digits, pos + 1);  //递归
            tmp.pop_back();  //要及时删除
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() <= 0)
            return {};
        result.clear();
        tmp = "";
        backtrack(digits, 0);
        return result;
    }
};
