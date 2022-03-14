class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        for(int i=1;i<n;++i){  //从1开始
            string curr = "";
            int start = 0, pos = 0;

            while(pos < pre.length()){
                while(pos < pre.length() && pre[start] == pre[pos])  //找到连续相同的字符串片段
                    ++pos;
                curr += (to_string(pos - start) + pre[start]);
                start = pos;
            }
            pre = curr;
        }
        return pre;
    }
};
