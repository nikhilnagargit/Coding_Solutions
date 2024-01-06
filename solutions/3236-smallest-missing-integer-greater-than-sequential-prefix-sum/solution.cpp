class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i=1;
        while(i<nums.size() and (nums[i]-1==nums[i-1])){
            sum+= nums[i];
            i++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<sum){
            }
            else if(nums[i]>sum){
                return sum;
            }
            else if(nums[i]==sum){
                sum+=1;
            }
            else{
                return nums[i];
            }
        }
        return sum;
    }
};
