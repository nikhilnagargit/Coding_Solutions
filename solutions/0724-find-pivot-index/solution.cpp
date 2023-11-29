class Solution {
public:
    int pivotIndex(vector<int>& nums){
        int right_sum = accumulate(nums.begin(),nums.end(),0); 
		//accumulate(first, last, sum) ,i.e sum : initial value of the sum
        int left_sum = 0;
        for(int i = 0;i < nums.size();i++){
            right_sum -= nums[i];
            if(left_sum == right_sum){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};
