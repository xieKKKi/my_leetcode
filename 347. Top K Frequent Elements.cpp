class Solution {
public:
    // cmp函数在作为类成员函数的时候一定需要static修饰
    // 因为所有在类内定义的非static成员函数在经过编译后隐式的添加了一个this指针参数  bool cmp(Solution *this, int a, int b)
    // 导致输入的cmp参数和sort()要求的参数不匹配
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;
        vector<int> ans;
        for(int n:nums){
            if(numsMap.find(n) != numsMap.end())
                ++numsMap[n];
            else
                numsMap[n] = 1;
        }

        vector< pair<int,int> > vec;
        for(unordered_map<int,int>::iterator it = numsMap.begin(); it != numsMap.end(); it++){
            vec.push_back( pair<int,int>(it->first,it->second) );
        }
        sort(vec.begin(),vec.end(),cmp);

        for(int i=0;i<k;++i){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
