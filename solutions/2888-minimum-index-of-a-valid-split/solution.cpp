class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominantNum = nums[0];
        int freq = 1;
        for(int i=1;i<nums.size();i++){
            if(dominantNum==nums[i]){
                freq++;
            }
            else{
                if(freq==0){
                    dominantNum = nums[i];
                    freq = 1;
                }
                else{
                    freq--;
                }
            }
        }

        int dominantNumFreq = 0;
        for(auto& n:nums){
            if(n==dominantNum){
                dominantNumFreq++;
            }
        }

        int leftfreq = 0;
        int rightfreq = dominantNumFreq;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==dominantNum){
                leftfreq++;
                rightfreq--;
            }

            if(leftfreq*2 > i+1 and rightfreq*2>(nums.size()-i-1)){
                return i;
            }
        }
        return -1;
    }
};
