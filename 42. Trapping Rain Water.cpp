class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftH(height.size()), rightH(height.size());  //左右对应最高高度
        leftH[0] = height[0];
        rightH[height.size()-1] = height[height.size()-1];
        for(int i=1;i<height.size();++i){
            leftH[i] = (leftH[i-1] >= height[i]) ? leftH[i-1] : height[i];
        }
        for(int i=height.size()-2;i>=0;--i){
            rightH[i] = (rightH[i+1] >= height[i]) ? rightH[i+1] : height[i];
        }

        int capacity = 0;
        for(int i=1;i<height.size()-1;++i){  //两端必然不储水
            if(height[i] < min(leftH[i], rightH[i]))
                capacity += (min(leftH[i], rightH[i]) - height[i]);
        }
        return capacity;
    }
};
