class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ;
        int countone = 0;
        for(int i=0;i<32;i++){
            int mask = 1<<i;
            for(int j=0;j<nums.size();j++){
                if((nums[j]&mask)!=0){
                    countone++;
                }
            }
            if(countone%3!=0){
                ans=ans|mask;
            }
            countone = 0;
        }
        return ans;
    }
};
