class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefixSumLR(nums.size(),0);
        vector<int> prefixSumRL(nums.size(),0);

        for(int i=1;i<nums.size();i++){
            prefixSumLR[i] = prefixSumLR[i-1]+nums[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            prefixSumRL[i] = prefixSumRL[i+1]+nums[i+1];
        }


        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 and prefixSumLR[i]==prefixSumRL[i]){
                count+=2;
            }
            else if(nums[i]==0 and (prefixSumLR[i]==prefixSumRL[i]+1 or prefixSumLR[i]==prefixSumRL[i]-1) ){
                count++;
            }
        }
        return count;
    }
};
