class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> m;
    double dfs(string source,string target,unordered_set<string>& visited,double ans){
        if(source==target){
            return ans;
        }
        for(auto neighborpair:m[source]){
            if(visited.find(neighborpair.first)==visited.end()){
                visited.insert(neighborpair.first);
                double a = dfs(neighborpair.first,target,visited,ans*neighborpair.second);
                if(a!=-1){
                    return a; 
                };
            }
        }
        return -1;
    }

    double solve(vector<string>& v){
        string source = v[0];
        string target = v[1];
        if(m.find(source)==m.end()){
            return -1;
        }
        unordered_set<string> visited;
        return dfs(source,target,visited,1);

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<values.size();i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double>ans;
        for(auto query:queries){
            ans.push_back(solve(query));
        }
        return ans;
    }
};
