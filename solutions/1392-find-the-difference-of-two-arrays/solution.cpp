class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> sa(nums1.begin(),nums1.end());
        unordered_set<int> sb(nums2.begin(),nums2.end());
        vector<int>v1;
        vector<int>v2;
        vector<vector<int>> ans;
        for(auto item:sa){
            if(sb.find(item)==sb.end()){
                v1.push_back(item);
            }
        }
        for(auto item:sb){
            if(sa.find(item)==sa.end()){
                v2.push_back(item);
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
