class Graph {
public:
    unordered_map<int,vector<pair<int,int>>> M;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        for(auto item:edges){
            M[item[0]].push_back({item[1],item[2]});
        } 
        N = n;
    }
    
    void addEdge(vector<int> item) {
         M[item[0]].push_back({item[1],item[2]});
    }

    int shortestPath(int curr_node, int target_node) {
        vector<int> dp (N,INT_MAX);
        dp[curr_node]=0;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,curr_node});

        while(!pq.empty()){
            int curr = pq.top().second;
            int cost_till_curr = pq.top().first;
            pq.pop();
            
            if(curr==target_node){
                return cost_till_curr;
            }

            for(auto item: M[curr]){
                int next = item.first;
                int cost_to_next = item.second;
                if(cost_till_curr+cost_to_next<dp[next]){
                    dp[next] = cost_till_curr+cost_to_next;
                    pq.push({dp[next],next});
                }
            }

        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
