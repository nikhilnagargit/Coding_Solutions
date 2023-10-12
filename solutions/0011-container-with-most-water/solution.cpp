class Solution {
public:
    int maxArea(vector<int>& height) {
       int left =0;
       int right = height.size()-1;
       int ans=0;
       while(right>left){
           ans = max(ans,(right-left)*min(height[right],height[left]));
           if(height[left]<height[right]){
               left++;
           }
           else{right--;}
       }
       return ans;
    }
};
