class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_in_left(n);
        max_in_left[0]= height[0];
        for(int i=1;i<n;i++){
            max_in_left[i] = max(max_in_left[i-1],height[i]);
        }
        max_in_left[n-1] = height[n-1];
        int water=0;
        for(int i=n-2;i>=0;i--){
            max_in_left[i]= min(max_in_left[i],max(max_in_left[i+1],height[i]));
            water+=max_in_left[i]-height[i];
        }
        return water;
    }
};
