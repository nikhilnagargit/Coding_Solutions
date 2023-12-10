class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int frq = 0;
        long long count = 0;
        while(j<nums.size()){
            if(nums[j]==maxi){
                frq++;
            }
            
        while(frq>=k){
                count+= nums.size()-j;
                if(nums[i]==maxi){
                    frq--;
                }
                i++;
            }
        j++;
        }
        return count;
    }
};
