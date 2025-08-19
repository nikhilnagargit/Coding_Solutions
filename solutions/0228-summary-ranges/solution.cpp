class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0) return ans;
        int prev = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1 != nums[i]){
                if(prev==nums[i-1])
                    ans.push_back(to_string(prev));
                else
                ans.push_back(to_string(prev)+"->"+to_string(nums[i-1]));
                prev = nums[i];
            }
        }
        if(prev==nums[nums.size()-1])
            ans.push_back(to_string(prev));
        else
        ans.push_back(to_string(prev)+"->"+to_string(nums[nums.size()-1]));
        return ans;
    }
};
