class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // append the n-1 items again back to the nums and use sliding window
        vector<int> v (nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            v.push_back(nums[i]);
        }
        int K = 0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) K++;
        }  

        int minZeros = INT_MAX;
        int left = 0 ;
        int zeros =0 ;
        int ones = 0 ;
        for(int right=0;right<v.size();right++){
            if(v[right]==1) ones++;
            else zeros++;
            if(right-left+1<K){
                continue;
            }
            while(right-left+1>K){
                if(v[left]==0) zeros--;
                else ones--;
                left++;
            }
            minZeros = min(minZeros,zeros);
        }
        return minZeros;
    }

};
