class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;  // 进位
            a = a ^ b;  // 不加进位的和
            b = carry;
        }
        return a;
    }
};
