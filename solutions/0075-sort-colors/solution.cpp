class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f =0;
        int b = nums.size()-1;
        int i=0;
        
        while(i<=b){
            if(nums[i]==0){
                swap(nums[i],nums[f]);
                f++;
                i++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[i],nums[b]);
                b--;
            }
            
            
            
        }
  
        
    }
};
