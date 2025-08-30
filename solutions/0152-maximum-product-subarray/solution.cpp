class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = INT_MIN;
        int p1 = 1;
        int p2 = 1;
        int n = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                p1 = 1;
                maxp = max({maxp,0,nums[i]});
            }
            else{
                p1= p1*nums[i];
                maxp = max({maxp,p1,nums[i]});
            } 

            if(nums[n-i]==0){
                p2 = 1;
                maxp = max({maxp,0,nums[n-i]});
            }
            else{
                p2= p2*nums[n-i];
                maxp = max({maxp,p2,nums[n-i]});
            }
        }
        return maxp;
    }
};
