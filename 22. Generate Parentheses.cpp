class Solution {
private:
    vector<string> result;
public:
    void backtrack(string strCurr, int n, int leftParenthesesNum){
        if(strCurr.length() == 2*n){  //长度已满足
            result.emplace_back(strCurr);
            return;
        }
        if(leftParenthesesNum == n){  //左括号已满
            strCurr.push_back(')');
            backtrack(strCurr, n, leftParenthesesNum);
        }
        else if(leftParenthesesNum*2 == strCurr.length()){  //右括号已满
            strCurr.push_back('(');
            backtrack(strCurr, n, leftParenthesesNum+1);
        }
        else{
            strCurr.push_back('(');
            backtrack(strCurr, n, leftParenthesesNum+1);
            strCurr.pop_back();  //记得要弹出一个
            strCurr.push_back(')');
            backtrack(strCurr, n, leftParenthesesNum);
        }
    }
    vector<string> generateParenthesis(int n) {
        result.clear();
        string strCurr = "";
        backtrack(strCurr, n, 0);
        return result;
    }
};
