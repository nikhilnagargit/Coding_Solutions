class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            int item = nums[j];
            int count = 1;
            nums[i] = nums[j];
            j++;
            i++;
            while(j<nums.size() and nums[j]==item){
                if(count==2){
                    j++;
                }
                else{
                    nums[i] = nums[j];
                    count++;
                    j++; 
                    i++;
                }

            }
        }
        return i;
    }
};
