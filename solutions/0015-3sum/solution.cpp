class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        int i=0;
        while(i<nums.size()-2){
            int start = i+1;
            int end = nums.size()-1;
            int target = -1*nums[i];
            while(start<end){
                if(nums[start]+nums[end]==target){
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[start]);
                    triplet.push_back(nums[end]);
                    ans.push_back(triplet);
                    start++;
                    end--;
                }
                else if(nums[start]+nums[end]>target){
                    end--;
                }
                else{
                    start++;
                }
            }
            while(nums[i]==nums[i+1] and i<nums.size()-2){
                i++;
            }
            i++;
        }
        set<vector<int>> myset;
        for(auto v:ans){
            myset.insert(v);
        }
        vector<vector<int>> modified_ans(myset.begin(),myset.end());
        return modified_ans;
    }
};
