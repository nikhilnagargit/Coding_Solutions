class Solution {
public:
    long long dfs(unordered_map<int,vector<int>>& adjList,unordered_set<int>& visited, int curr, int& count,int& k,vector<int>& values){
        if(visited.count(curr)==0){
            visited.insert(curr);
        }
        else{
            return 0;
        }
        long long sum = values[curr];
        for(auto& neighbor:adjList[curr]){
            if(visited.count(neighbor)==0){
               sum+= 1ll*dfs(adjList,visited,neighbor,count,k,values);
               sum = sum%k;
            }
        }
        if(sum%k==0){
            count++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>> adjList;
        for(auto& e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        unordered_set<int> visited;
        int count = 0;
        long long sum = dfs(adjList,visited,0,count,k,values);
        return count;
    }
};
