class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        else if((n & 1) == 0)  //&1 == 0，是偶数
            return myPow(x*x, n/2);
        else
            return (n > 0 ? x : 1.0 / x) * myPow(x*x, n/2);  //n必将经过1变成0，所以要在这里判断n的符号
    }
};
