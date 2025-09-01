class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //prims algorithm
        unordered_map<int,vector<pair<int,int>>> adjList;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adjList[i].push_back({j,cost});
                adjList[j].push_back({i,cost});
            }
        }

        //find total cost of minimum spanning tree 
        //start with point 0

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        min_heap.push({0,0});
        int total_cost = 0;
        unordered_set<int> visited;
        int loop = 0;
        while(loop<points.size()){
            //pop the heap element of min cost
            auto p = min_heap.top();
            min_heap.pop();
            if(visited.count(p.second)){
                continue;
            }
            total_cost+= p.first;
            loop++;
            //explore the neighbors of curr
            //mark as visited
            visited.insert(p.second);
            for(auto neighbor:adjList[p.second]){
     
                min_heap.push({neighbor.second,neighbor.first});
            }
        }
        return total_cost;

    }
};
