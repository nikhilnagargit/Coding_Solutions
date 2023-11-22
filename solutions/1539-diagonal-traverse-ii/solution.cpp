class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map <int,vector<int>> m;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        int i=0;
        while(m.find(i)!=m.end()){
            for(int j=0;j<m[i].size();j++){
                ans.push_back(m[i][j]);
            }
            i++;
        }
        return ans;
    }
};
