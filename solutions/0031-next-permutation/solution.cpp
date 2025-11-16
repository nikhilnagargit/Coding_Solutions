class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the descending suffix subarray
        // swap the,  prev and first item of suffix array
        // sort the new suffix
        int suffixfirstidx = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                suffixfirstidx = i;
                break;
            }
        }
        if(suffixfirstidx==-1){
            //sort the while array
            sort(nums.begin(),nums.end());
        }
        else{
            //find the just bigger number to swap
            for(int k=nums.size()-1;k>=suffixfirstidx+1;k--){
                if(nums[k]>nums[suffixfirstidx]){
                     swap(nums[suffixfirstidx],nums[k]);
                     break;
                }
            }
            sort(nums.begin()+suffixfirstidx+1,nums.end());
        }

    }
};
