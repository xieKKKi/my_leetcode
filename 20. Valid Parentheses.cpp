class Solution {
public:
    bool isValid(string s) {
        stack<char> strStack;
        for(int i=0;i<s.length();++i){
            switch(s[i]){
            case ']':
                if(!strStack.empty() && strStack.top() == '[')
                    strStack.pop();
                else
                    return false;
                break;
            case '}':
                if(!strStack.empty() && strStack.top() == '{')
                    strStack.pop();
                else
                    return false;
                break;
            case ')':
                if(!strStack.empty() && strStack.top() == '(')
                    strStack.pop();
                else
                    return false;
                break;
            default:
                strStack.push(s[i]);
                break;
            }
        }
        if(strStack.empty())
            return true;
        else
            return false;
    }
};
