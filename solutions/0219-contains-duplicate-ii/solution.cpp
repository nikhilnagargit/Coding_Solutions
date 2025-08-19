class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<=min(k,(int)nums.size()-1);i++){
            m[nums[i]]++;
            if(m[nums[i]]>1) return true;
        }
        //sliding window
        int left = 0;
        for(int right=k+1;right<nums.size();right++){
            //add right in sliding window
            m[nums[right]]++;
            //remove left from sliding window
            m[nums[left]]--;
            
            if(m[nums[right]]>1){
                return true;
            }
            left++;
        }
        return false;
    }
};
