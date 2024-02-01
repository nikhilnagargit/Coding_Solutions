class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums.size()%3!=0)return ans;
        vector<int>v;
        for(int i=2;i<nums.size();i+=3){
            if(nums[i]-nums[i-2]<=k ){
                v.push_back(nums[i-2]);
                v.push_back(nums[i-1]);
                v.push_back(nums[i]);
                ans.push_back(v);
            }
            else{
                return vector<vector<int>>();
            }
            v.clear();
        }
        return ans;
    }
};
