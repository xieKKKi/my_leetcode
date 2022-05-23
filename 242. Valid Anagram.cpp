class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chMap;
        for(char ch:s){
            if(chMap.count(ch) == 0)
                chMap[ch] = 1;
            else
                ++chMap[ch];
        }
        for(char ch:t){
            if(chMap.count(ch) == 0)
                return false;
            else
                --chMap[ch];
        }
        for(auto it=chMap.begin();it!=chMap.end();++it){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};
