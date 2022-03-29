class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)  return 1;
        if(n == 2)  return 2;
        int x1 = 1, x2 = 2, x3 = x1 + x2;
        for(int i = 3; i < n; ++i){
            x1 = x2;
            x2 = x3;
            x3 = x1 + x2;
        }
        return x3;
    }
};
