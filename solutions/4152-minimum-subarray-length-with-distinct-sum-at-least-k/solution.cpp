class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int left = 0;
        int mini = INT_MAX;
        long long sum = 0;
        unordered_map<int,int> freq;
        for(int right=0;right<nums.size();right++){
            if(freq[nums[right]]==0){
                sum+= nums[right];
            }
            freq[nums[right]]++;
            //start shrinking
            while(left<=right and sum>=k){
                mini = min(mini,right-left+1);
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    sum = sum - nums[left];
                }
                left++;
                // mini = min(mini,right-left+1);
            }
         
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};
