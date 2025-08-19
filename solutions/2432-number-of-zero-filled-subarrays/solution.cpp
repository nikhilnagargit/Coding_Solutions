class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long sum = 0;
        for(auto& n:nums){
            if(n==0){
                count++;
            }
            else{
                sum+= (count*(count+1))/2;
                count = 0;
            }
        }
        sum+= (count*(count+1))/2;
        return sum;
    }
};
