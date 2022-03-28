class Solution {
public:
    // 二分法
    int mySqrt(int x) {
        if(x <= 0)  return 0;
        if(x >= INT_MAX - 88047) return 46340;
        
        int root = 1;
        while(root < 46340 && root*root <= x)
            root *= 2;
        root /= 2;
        while(root*root <= x)
            ++root;
        --root;

        return root;
    }
};

class Solution2 {
public:
    // 牛顿迭代法
    int mySqrt(int x) {
        if(x <= 0)  return 0;
        if(x >= INT_MAX - 88047) return 46340;

        double y = x, y1 = x;

        while(true){
            y1 = y - (y * y - x) / (2 * y);
            if(fabs(y1 - y) < 1e-1)
                break;
            y = y1;
        }
        return int(y1);
    }
};
