class Solution {
public:
    unordered_map<int,vector<int>> neighbors;
    unordered_set<int>visited;

    bool dfs(int source){
        if(visited.find(source)!=visited.end()) return true;
        visited.insert(source);
        if(neighbors.find(source)==neighbors.end()){
            visited.erase(source);
            return false;
        }
        for(auto neighbor:neighbors[source]){
            if(dfs(neighbor))return true;
        }
        visited.erase(source);
        neighbors.erase(source);
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        for(auto prerequisite: prerequisites){
            neighbors[prerequisite[0]].push_back(prerequisite[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(dfs(i)) return false;
        }
        return true;
    }
};
