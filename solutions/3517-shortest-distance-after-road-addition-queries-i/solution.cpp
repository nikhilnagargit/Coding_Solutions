class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> adjList ;
        vector<int>ans;
        vector<int> min_distances(n,0);
        for(int i=0;i<n;i++){
            min_distances[i] = i;
        }

        for(int i=0;i<n-1;i++){
            adjList[i].insert(i+1);
        }

        for(auto query:queries){
            min_distances[query[1]] = min(min_distances[query[0]]+1,min_distances[query[1]]);
            adjList[query[0]].insert(query[1]);
            //start from where query started
            queue<int> q;
            q.push(query[0]);
            unordered_set<int> visited;

            //do the traversal
            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    int curr = q.front();q.pop();
                    if(visited.count(curr)){
                        continue;
                    }
                    for(auto adj:adjList[curr]){
                        min_distances[adj] = min(min_distances[curr]+1,min_distances[adj]);
                        q.push(adj);
                    }
                    visited.insert(curr);
                }
            }
            ans.push_back(min_distances[n-1]);
        }

        return ans;
    }
};
