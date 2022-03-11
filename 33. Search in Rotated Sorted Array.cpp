class Solution {
public:
    vector<int> Nums;
    int Target;
    int searchNum(int left, int right){ //二分法
        if(Nums[left] == Target)
            return left;
        else if(Nums[right] == Target)
            return right;
        else if(right - left <= 1)
            return -1;

        int mid = (left + right) / 2;
        if(Target <= Nums[mid] && Target <= Nums[right]){  //同时小于，取较小那边的区间
            if(Nums[mid] < Nums[right])
                return searchNum(left, mid);
            else    
                return searchNum(mid, right);
        }
        else if(Target <= Nums[mid])
            return searchNum(left, mid);
        else if(Target <= Nums[right])
            return searchNum(mid, right);
        else if(Target >= Nums[mid] && Target >= Nums[right]){  //同时大于，取较大那边的区间
            if(Nums[left] > Nums[mid])
                return searchNum(left, mid);
            else    
                return searchNum(mid, right);
        }
        else if(Target >= Nums[left])
            return searchNum(left, mid);
        else  //Target >= Nums[mid]
            return searchNum(mid, right);
    }
    int search(vector<int>& nums, int target) {
        Nums = nums;
        Target = target;
        return searchNum(0, Nums.size() - 1);
    }
};
