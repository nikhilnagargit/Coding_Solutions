class Solution {
public:
    int toggle(int num){
        if(num){
            return 0;
        }
        return 1;
    }

    int maximumLength(vector<int>& nums) {
        int flag = 1;
        int i = 0;
        int count = 0;
        while(i<nums.size()){
            if(nums[i]%2==flag){
                count++;
                flag = toggle(flag);
            }
            i++;
        }

        int count2 = 0;
        i=0;
        flag=0;
        while(i<nums.size()){
            if(nums[i]%2==flag){
                count2++;
                flag = toggle(flag);
            }
            i++;
        }

        i = 0;
        int count3 = 0;
        flag = 1;
        while(i<nums.size()){
            if(nums[i]%2==flag){
                count3++;
            }
            i++;
        }

        int count4 = 0;
        i=0;
        flag=0;
        while(i<nums.size()){
            if(nums[i]%2==flag){
                count4++;
            }
            i++;
        }


        return max(count,max(count2,max(count3,count4)));

    }
};
