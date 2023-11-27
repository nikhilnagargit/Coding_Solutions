class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi = INT_MIN;
        int n = nums.size();
        int left = 0;
        int right = k;
        double sum = 0;
        for(int i=0;i<k;i++){
            sum+= nums[i];
        } 
        maxi = sum/k;
        while(right<n){
            sum = sum+nums[right]-nums[left];
            maxi = max(maxi,(sum/k));
            left++;
            right++;
        }
        return maxi;
    }
};
