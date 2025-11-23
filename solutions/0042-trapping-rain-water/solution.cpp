class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> nextBiggest(height.size(),0);
        int biggest = -1;
        for(int i=height.size()-1;i>=0;i--){
            nextBiggest[i] = biggest;
            if(height[i]>=biggest){
                biggest = height[i];
            }
        }
        int water =0;
        int leftBiggest = -1;
        for(int i=0;i<height.size();i++){
            water += max(max(0,min(leftBiggest,nextBiggest[i]))-height[i],0);
            leftBiggest = max(leftBiggest,height[i]);
        }
        return water;
    }
};
