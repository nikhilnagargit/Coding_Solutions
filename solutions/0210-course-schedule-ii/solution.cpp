class Solution {
public:
        vector<int>ans;
        unordered_set<int>ansset;
    unordered_map<int,vector<int>>m;
    unordered_set<int>vis;
    bool dfs(int s){
        if(vis.count(s)) return true;
        vis.insert(s);
        for(auto nb:m[s]){
            if(dfs(nb))return true;
        }
        m.erase(s);
        vis.erase(s);
        if(ansset.find(s)==ansset.end()){
        ans.push_back(s);
        ansset.insert(s);
        }
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prqs) {
        for(auto prq:prqs){
            m[prq[0]].push_back(prq[1]);
        }
        for(int i=0;i<n;i++){
            if(dfs(i))return vector<int>();
        }
        return ans;
    }
};
