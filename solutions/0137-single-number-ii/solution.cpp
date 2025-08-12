class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int mask = 1<<i;
            int ones = 0;
            for(auto n:nums){
                if(n&mask){
                    ones+=1;
                }
            }
            if(ones%3==1){
                ans = ans|mask;
            }
        }
        return ans;
    }
};
