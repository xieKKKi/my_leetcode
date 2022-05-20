class Solution {
public:
    int calculate(string s) {
        vector<int> numStack;
        int num = 0;
        char preSign = '+';
        for(int i = 0;i<s.length();++i){
            if(isdigit(s[i]))
                num = num * 10 + int(s[i] - '0');
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.length()-1){
                switch(preSign){
                    case '+':
                        numStack.push_back(num);
                        break;
                    case '-':
                        numStack.push_back(-num);
                        break;
                    case '*':
                        numStack.back() *= num;
                        break;
                    case '/':
                        numStack.back() /= num;
                        break;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(numStack.begin(), numStack.end(), 0);
    }
};
