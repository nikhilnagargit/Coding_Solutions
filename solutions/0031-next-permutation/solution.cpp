class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint = 0;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                continue;
            }
            breakpoint = i;
            break;
        }
        // cout<<breakpoint;
        //find the next greater number of breakpoint
        //swap with it
        int nextgreater = nums[breakpoint];
        int nextgreateridx = breakpoint;
        for(int i=breakpoint+1;i<nums.size();i++){
            if(nums[i]<nextgreater and breakpoint>0 and nums[breakpoint-1]<nums[i]){
                nextgreater = nums[i];
                nextgreateridx = i;
            }
        }
        if(breakpoint!=0)
        swap(nums[breakpoint-1],nums[nextgreateridx]);
        sort(nums.begin()+breakpoint,nums.end());
    }
};

//find the breakpoint
//all left to breakpoinrt sort them
//all right to breakpoint will be same
//breakpoint will be first item from last which is lesser than next
// 422432 -> 424223.  423224

// 42221 -> 12224

// 16789 -> 16798
