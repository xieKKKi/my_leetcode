class Solution {
private:
    vector<vector<string>> result;
    vector<string> tmp;
    string str;

    bool isPalindrome(int l, int r){
        while(l < r){
            if(str[l] != str[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
    void backtrack(int pos){
        if(pos >= str.length()){
            result.push_back(tmp);
            return;
        }
        for(int i = pos;i < str.length(); ++i){
            if(isPalindrome(pos, i)){
                tmp.push_back(str.substr(pos, i-pos+1));
                backtrack(i+1);
                tmp.pop_back();
            }
        }
    }

public:
    Solution(){
        result.clear();
        tmp = {};
    }
    vector<vector<string>> partition(string s) {
        str = s;
        backtrack(0);
        return result;
    }
};
