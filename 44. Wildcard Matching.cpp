class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, lasti = 0, lastj = -1; //这里lastj为-1，是为了做标记

        while(i < s.length()){
            if(j < p.length()) //s不为空时p为空了
            {
                if(s[i] == p[j] || p[j] == '?'){
                    ++i;
                    ++j;
                    continue;
                }
                if(p[j] == '*'){  //记录位置，跳过*继续匹配
                    lasti = i;
                    lastj = j;
                    ++j;
                    continue;
                }
            }
            
            //到这一步，就是匹配失败了，此时要检查之前是否有*出现
            if(lastj >= 0){
                j = lastj + 1;  //p回溯到*的后一个字符
                i = ++lasti;   //lasts往后移一位
                continue;
            }
            return false;  //还不行就是失败了
        }

        while(j < p.length() && p[j] == '*') ++j;  //p后面必须全为*
        return j == p.length();
    }
};
