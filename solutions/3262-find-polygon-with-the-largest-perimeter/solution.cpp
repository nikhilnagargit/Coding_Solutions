class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum = accumulate(nums.begin(),nums.end(),static_cast<long long>(0));
        for(long long i=0;i<nums.size();i++){
            long long side = nums[i];
            sum = sum-side;
            if(sum>side){
                return sum+side;
            }
        }
        return -1;

    }
};
