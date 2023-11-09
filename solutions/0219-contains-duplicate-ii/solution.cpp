class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;
        int n = nums.size();
        for(int i=0;i<min(k+1,n);i++){
            if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        int i=k+1;
        int j=0;
        while(i<nums.size()){
             s.erase(nums[j]);
             if(s.find(nums[i])!=s.end()){
                return true;
            }
            s.insert(nums[i]);
            j++;
            i++;
        }
        return false;
    }
};
