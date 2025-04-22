class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>lrv(height.size(),0);
        vector<int>rlv(height.size(),0);
        lrv[0]=height[0];
        for(int i=1;i<height.size();i++){
            lrv[i] = max(lrv[i-1],height[i]);
        }
        rlv[height.size()-1] = height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            rlv[i] = max(rlv[i+1],height[i]);
        }
        int water = 0;
        for(int i=1;i<height.size()-1;i++){
            water += max(min(lrv[i-1],rlv[i+1])-height[i],0);
        }
        return water;
    }
};
