class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> chMap;
        for(char ch:s){
            ++chMap[ch];
        }
        int pos = 0, ans = 0;
        for(int i=0;i<s.length();++i){
            if(chMap[s[i]] < k){
                if(i - pos >= k){
                    int tmp = longestSubstring(s.substr(pos, i - pos), k);
                    ans = ans > tmp ? ans : tmp;
                }
                pos = i+1;
            }
        }
        if(pos == 0){
            if(s.length() >= k)
                ans = s.length();
        }
        else{  // 最后一位也要考虑
            int tmp = longestSubstring(s.substr(pos, s.length() - pos), k);
            ans = ans > tmp ? ans : tmp;
        }
        return ans;
    }
};
