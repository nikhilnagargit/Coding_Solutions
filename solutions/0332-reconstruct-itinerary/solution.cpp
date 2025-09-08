class Solution {
public:
    vector<string> ans;
    void dfs(unordered_map<string,vector<string>>& m,string curr){
        while(m[curr].size()!=0){
            string neighbor = m[curr][m[curr].size()-1];
            m[curr].pop_back();
            dfs(m,neighbor);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> m;
        int totaledges = 0;
        for(auto& t:tickets){
            m[t[0]].push_back(t[1]);
            totaledges++;
        }
        for(auto& item:m){
            sort(item.second.begin(),item.second.end(),greater<string>());
        }
      
        dfs(m,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
