class Solution {
public:
    
    // void bfs( unordered_map<int,vector<int>>& graph,int dist,unordered_set<int>visited,int curr,vector<int>&v){
    //     if(visited.find(curr)==visited.end()){
    //         visited.insert(curr);
    //     }
    // }
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int,vector<int>> graph;
        for(int i=1;i<n;i++){
            graph[i].push_back(i+1);
            graph[i+1].push_back(i);
        }
        
        if(x!=y){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        vector<int>v(n,0);
        for(int i=1;i<=n;i++){
            unordered_set<int> visited;
            queue<int> q;
            q.push(i);
            int dist = 0;
            while(!q.empty()){
                int size  = q.size();
                for(int i=0;i<size;i++){
                    int item = q.front();
                    q.pop();
                    visited.insert(item);
                    for(auto neighbor:graph[item]){
                        if(visited.find(neighbor)==visited.end()){
                            visited.insert(neighbor);
                            q.push(neighbor);
                            v[dist]++;
                        }
                    }
                }
                dist++;
            }
        }
        return v;
    }
};
