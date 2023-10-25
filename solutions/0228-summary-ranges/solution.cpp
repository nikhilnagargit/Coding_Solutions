class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string> ans;
        if(nums.size()==0){
          return ans;
        }
        int start=nums[0];
        int end = nums[0];
        int i=1;
   
        while(i<nums.size()){
            if(nums[i]-1==end){
                end = nums[i];
            }
            else{
                // print previoud range
                if(start==end){
                    ans.push_back(to_string(start));
                }
                else
                ans.push_back(to_string(start)+"->"+to_string(end));
                start = nums[i];
                end = nums[i];
            }
            i++;
        }
                if(start==end){
                    ans.push_back(to_string(start));
                }
                else
                ans.push_back(to_string(start)+"->"+to_string(end));
        return ans;
    }
};
