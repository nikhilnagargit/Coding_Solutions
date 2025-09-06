class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //slow and fast pointer like linked list
        int slow = 0;
        int fast = 0;
        int flag = true;

       while(slow!=fast or flag){
        flag = false;
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int a = slow;
        int b = 0;
        while(a!=b){
            a = nums[a];
            b = nums[b];
        }

        return a;
    }
};
