class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset;
        for(auto& n:nums) myset.insert(n);

        int maxCount = 0;
        int i=0;
        while(i<nums.size()){
            if(myset.find(nums[i]-1)!=myset.end()){
                i++;
            }
            else{
                int count = 0;
                while(myset.count(nums[i])>0 ){
                    count++;
                    nums[i]++;
                }
                maxCount = max(maxCount,count);
                if(maxCount>(nums.size()/2)){
                    return maxCount;
                }
                i++;
            }
        }
        return maxCount;
    }
};
