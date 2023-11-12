class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>> adjList;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                adjList[routes[i][j]].push_back(i);
            }
        }
        int bus_count=1;
        queue<int> q;
        unordered_set<int> visited;

        // all the source nodes should be filled in queue
        for(auto idx:adjList[source]){
                q.push(idx);
                visited.insert(idx);
            
        }
        // it is a multisource bfs
        while(q.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curr = q.front();q.pop();

                for(auto stop:routes[curr]){
                    if(stop==target){
                        return bus_count;
                    }
                    for(auto node:adjList[stop]){
                        if(visited.find(node)==visited.end()){
                            q.push(node);
                            visited.insert(node);
                        }
                    }
                }
            }
            bus_count++;
        }
        return -1;
    }
};
