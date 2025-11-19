class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        int first = 0;
        int second = 0;

        for(int i=0;i<nums.size();i++){
            if(s.count(target-nums[i])){
                second = i;
                break;
            }
            else{
                s.insert(nums[i]);
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target-nums[second]){
                first = i;
                break;
            }
        }

        return {first,second};

    }
};
