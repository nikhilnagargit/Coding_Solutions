class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>&mp,string curr,double costtillnow,string target,unordered_set<string>&visited,double& cost){
        if(curr==target){
            cost = costtillnow;
            return ;
        }
        if(visited.count(curr)){
            return;
        }
        visited.insert(curr);
        for(auto& neighbor:mp[curr]){
            dfs(mp,neighbor.first,costtillnow*neighbor.second,target,visited,cost);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mp;

        for(int i=0;i<equations.size();i++){
            vector<string>  e = equations[i];
            mp[e[0]].push_back({e[1],values[i]});
            mp[e[1]].push_back({e[0],1.0/values[i]});
        }

        vector<double> ans;

        for(auto& q:queries){
            string start = q[0];
            string end = q[1];
            if(mp.find(start)==mp.end()){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double cost =-1.0;
            dfs(mp,start,1.0,end,visited,cost);
            ans.push_back(cost);
        }
        return ans;

    }
};
