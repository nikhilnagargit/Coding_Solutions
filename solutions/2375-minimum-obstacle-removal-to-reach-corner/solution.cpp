class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minDistance(m,vector<int>(n,INT_MAX));
        minDistance[0][0] = 0;
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> heap; 
        // priority_queue<vector<int>> heap;
        heap.push({0,0,0});
        // unordered_set<string> visited;
        while(!heap.empty()){
            auto curr = heap.top();heap.pop();
            int i = curr[1];
            int j = curr[2];
            int distance = curr[0];
            if(i==m-1 and j==n-1){
                return distance;
            }
            // string s = to_string(i)+"-"+to_string(j);
            //go in 4 directions if valid
            if(i-1>=0){
               int newDistance = distance + grid[i-1][j];
                if(newDistance < minDistance[i-1][j]) {
                    heap.push({newDistance,i-1,j});
                     minDistance[i-1][j] = newDistance;
                }
                
            }
            if(j-1>=0){
               int newDistance = distance + grid[i][j-1];
                if(newDistance < minDistance[i][j-1]) {
                    heap.push({newDistance,i,j-1});
                     minDistance[i][j-1] = newDistance;
                }               
            }
            if(i+1<m){
               int newDistance = distance + grid[i+1][j];
                if(newDistance < minDistance[i+1][j]) {
                    heap.push({newDistance,i+1,j});
                     minDistance[i+1][j] = newDistance;
                }           
            }
            if(j+1<n){
               int newDistance = distance + grid[i][j+1];
                if(newDistance < minDistance[i][j+1]) {
                    heap.push({newDistance,i,j+1});
                     minDistance[i][j+1] = newDistance;
                }           
            }
           
        }

        return minDistance[m-1][n-1];
    }
};
