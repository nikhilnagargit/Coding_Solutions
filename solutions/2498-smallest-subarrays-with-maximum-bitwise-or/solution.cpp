class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> pos(32,-1);
        for(int i=nums.size()-1;i>=0;i--){
            int j=i;
            for(int bit=0;bit<32;bit++){
                // cout<<(nums[i]&(1<<bit))<<endl;
                if((nums[i]&(1<<bit))){
                    pos[bit]=i;
                }
                else {
                    j = max(j,pos[bit]);
                }
            }

            ans[i] = j-i+1;
        }
        return ans;
    }
};
