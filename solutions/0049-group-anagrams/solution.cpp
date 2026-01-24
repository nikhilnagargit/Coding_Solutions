class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(auto s:strs){
            string sc = s;
            sort(sc.begin(),sc.end());
            m[sc].push_back(s);
        }
        vector<vector<string>>ans;

        for(auto [key,value] : m){
            ans.push_back(value);
        }
        return ans;
    }
};
