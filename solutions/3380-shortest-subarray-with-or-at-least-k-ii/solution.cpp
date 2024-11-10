class Solution {
public:

    void push_in_count_arr(int num, vector<int>& countArr){
        int mask = 1;
        for(int i=0;i<32;i++){
            int curr_bit = num&mask;
            mask = mask<<1;
            if(curr_bit!=0){
                countArr[i]= countArr[i]+1;
            }
        }
    }

    void remove_from_count_arr(int num,vector<int>& countArr){
        int mask = 1;
        for(int i=0;i<32;i++){
            if((mask & num) !=0)
            if(countArr[i]>=1){
                countArr[i] = countArr[i]-1;
            }
            mask = mask<<1;
        }
    }

    int convert_int_from_count_arr(vector<int>& countArr){
        int ans = 0;
        int mask = 1;
        for(int i=0;i<32;i++){
            if(countArr[i]!=0){
                ans = ans|mask;
            }
            mask = mask<<1;
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> countArr(32,0);
        int left = 0;
        int right = 0;
        int mini = INT_MAX;
        int result = 0;
        while(right<nums.size()){
            push_in_count_arr(nums[right],countArr);
            while(left<=right and convert_int_from_count_arr(countArr)>=k){
                mini = min(mini,right-left+1);
                remove_from_count_arr(nums[left],countArr);
                left++;
            }
            right++;
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};

