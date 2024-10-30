class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> idp (nums.size(),1);
        vector<int> ddp (nums.size(),1);

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    idp[i] = max(idp[i],1+idp[j]);
                }
            }

        }

        for(int i=nums.size()-2;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    ddp[i] = max(ddp[i],1+ddp[j]);
                }
            }
        }
        int max_mountain = -1;

        for(int i=0;i<nums.size();i++){
            if(ddp[i]!=1 and idp[i]!=1)
            max_mountain = max(max_mountain, idp[i]+ddp[i]-1);
        }
        return nums.size()-max_mountain;
    }
};
