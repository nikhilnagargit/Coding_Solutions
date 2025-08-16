class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            //find the first num which has diff more than curr num
            int target = 2*nums[i];
            int idx = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;
            cout<<idx<<",";
            if(idx>=nums.size()){
                ans+= nums.size()-i-1;
            }
            else if(idx<=i){
                ans+=0;
            }
            else if(nums[idx]>target){
                ans+= idx-i-1;
            }
            else{
                ans+= idx-i;
            }
        }
        return ans;
    }
};
