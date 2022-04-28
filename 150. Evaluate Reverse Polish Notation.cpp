class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string str:tokens){
            if(str.length() > 1 || '0' <= str[0] && str[0] <= '9')
                nums.push(stoi(str));
            else{
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if(str[0] == '+')   nums.push(num1 + num2);
                else if(str[0] == '-') nums.push(num1 - num2);
                else if(str[0] == '*') nums.push(num1 * num2);
                else if(str[0] == '/') nums.push(num1 / num2);
            }
        }
        return nums.top();
    }
};
