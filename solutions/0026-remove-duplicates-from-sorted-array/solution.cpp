class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        int a=0;
        int b=1;

        
        while(b<nums.size()){
            if(nums[b]==nums[b-1]){
                b++;
            }
            else{
                a++;
                nums[a] = nums[b];
                b++;
            }
            
        }
        return a+1;
    }
};
