class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // first find the initial width of sliding window
        int i=0;
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            if(sum>=target){
                break;
            }
            i++;
        }

        if(i==nums.size()){
            return 0;
        }

        int left = 0;
        int right = i;
        int width = i+1;
        int min_width = width;

        while(right<nums.size() and left<=right and left<nums.size()){
            if(sum>=target){
                min_width = min(min_width,width);
                width--;
                left++;
                if(left-1<nums.size())
                sum = sum-nums[left-1];
            }
            else{
                width++;
                right++;
                if(right<nums.size())
                sum = sum+nums[right];
            }

        }

        return min_width;
    }
};
