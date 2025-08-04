class Solution {
public:
    unordered_map<int,vector<int>>m;
    unordered_set<int> path_visited;
    bool dfs(int curr, unordered_set<int>& visited){
        if(m.find(curr)==m.end()){
            return true;
        }
        if(visited.count(curr)){
            return false;
        }

        visited.insert(curr);
        for(auto& n:m[curr]){
            if(!dfs(n,visited)){
                return false;
            }
        }
        visited.erase(curr);
        m[curr]=vector<int>();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& p:prerequisites){
            m[p[0]].push_back(p[1]);
        }
        unordered_set<int> visited;
        // for each node , check if you can cycle
        for(int item = 0 ;item<numCourses;item++){
            if(!dfs(item,visited)){
                return false;
            }
        }
        return true;
    }
};
