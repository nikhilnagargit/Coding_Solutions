class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto item:strs){
            string s = item;
            sort(s.begin(),s.end());
            m[s].push_back(item);
        }

        vector<vector<string>>ans;
        for(auto item:m){
            ans.push_back(item.second);
        }
        return ans;
    }
};
