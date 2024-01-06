class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorproduct = nums[0];
        for(int i=1;i<nums.size();i++){
            xorproduct = xorproduct^nums[i];
        }
        int count  = 0;
        for(int i=0;i<32;i++){
            if(((1<<i) & xorproduct)!=0){
                if(((1<<i) & k)!=0){
                    
                }
                else{
                    count++;
                }
            }
            else{
                if(((1<<i) & k)!=0){
                    count++;
                }
                else{
                }
            }
        }
        return count;
    }
};
