class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int prevprev = nums[0];
        int prev = nums[1];
        int index =2;

        for(int h=2;h<nums.size();h++){
            int n = nums[h];
            if(n!=prev){
                nums[index]=n;
                index++;
                prevprev = prev;
                prev = n;
            }
            else if(n==prev and n!=prevprev){
                nums[index]=n;
                index++;
                prevprev = n;
            }
            else{
                prevprev= prev;
                prev= n;
            }
        }
        return index;
    }
};
