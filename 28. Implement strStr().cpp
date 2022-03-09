class Solution {
public:
    //KMP法
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        //设置哨兵
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        vector<int> next(m + 1);
        //预处理next数组
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = next[j];
            if(p[i] == p[j + 1]) j++;
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = next[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return i - m;
        }
        return -1;
    }


    //BF方法
    // bool compareString(const string a, const string b){  //默认a,b等长
    //     for(int i=0;i<a.length();++i){
    //         if(a[i] != b[i])
    //             return false;
    //     }
    //     return true;
    // }
    // int strStr(string haystack, string needle) {
    //     if(haystack.length() < needle.length())
    //         return -1;

    //     for(int i=0;i<haystack.length()-needle.length()+1;++i){
    //         if(compareString(needle, haystack.substr(i, needle.length())))
    //             return i;
    //     }
    //     return -1;
    // }
};
