class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxi = 0 ;
        while(left<right){
            maxi = max(maxi,(right-left)*min(height[right],height[left]));
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxi;
    }
};
