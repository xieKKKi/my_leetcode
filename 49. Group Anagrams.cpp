class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > groupMap;  //无序比有序快
        vector<vector<string>> res;  
        for(string str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());  //对字符串进行排序
            groupMap[tmp].push_back(str);   
        }
        for(const auto it:groupMap)
            res.push_back(it.second);
        return res;
    }
};

