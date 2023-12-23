class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        if(nums.size()<3){
            return -1;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long i = 0 ;
        // cout<<endl;
        // for(int k=0;k<nums.size();k++){
        //     cout<<nums[k]<<",";
        // }
        // cout<<endl;
        long long totalsum = 0;
        for(auto item:nums){
            totalsum+=item;
        }
        // cout<<totalsum<<endl;
        while(i<=nums.size()-3){
            long long curr = nums[i];
            
            if((totalsum-curr)>curr){
                return totalsum;
            }
            
                totalsum = totalsum-curr;
            
            i++;
        }
        return -1;
        

    }
};
