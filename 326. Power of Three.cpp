class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n > 0){
            double res = log(n)/log(3);
            if(fabs(res - round(res)) < 0.0000000001)
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
