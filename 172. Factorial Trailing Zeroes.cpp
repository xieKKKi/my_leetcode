class Solution {
public:
    int trailingZeroes(int n) {
        int count5 = 0;
        while(n){
            n /= 5;
            count5 += n;
        }
        return count5;
    }
};
