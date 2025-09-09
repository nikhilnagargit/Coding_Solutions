class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& visited, vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(auto& dir : dirs){
                int ni = i + dir.first;
                int nj = j + dir.second;
                // Check bounds + ensure water can "flow" (reverse logic: move from lower/equal to higher/equal)
                if(ni >= 0 && nj >= 0 && ni < m && nj < n 
                   && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]){
                    visited[ni][nj] = 1;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));
        queue<pair<int,int>> qP, qA;
        
        // Pacific border (top + left edges)
        for(int i=0;i<m;i++){
            pacific[i][0] = 1;
            qP.push({i,0});
        }
        for(int j=0;j<n;j++){
            pacific[0][j] = 1;
            qP.push({0,j});
        }
        
        // Atlantic border (bottom + right edges)
        for(int i=0;i<m;i++){
            atlantic[i][n-1] = 1;
            qA.push({i,n-1});
        }
        for(int j=0;j<n;j++){
            atlantic[m-1][j] = 1;
            qA.push({m-1,j});
        }
        
        // BFS from borders
        bfs(qP, pacific, heights);
        bfs(qA, atlantic, heights);
        
        // Collect cells that can reach both oceans
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};

