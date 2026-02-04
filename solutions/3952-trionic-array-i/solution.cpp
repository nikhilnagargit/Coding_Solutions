class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int peakcount =0 ;
        int vallycount =0 ;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1] or nums[i]==nums[i+1]) return false;
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1]) peakcount++;
            if(nums[i]<nums[i-1] and nums[i]<nums[i+1]) vallycount++;
            if(vallycount>peakcount) return false;

        }
        if(peakcount==1 and vallycount ==1)
        return true;
        return false;
    }
};
