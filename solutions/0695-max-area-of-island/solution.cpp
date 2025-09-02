class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j, vector<vector<bool>>&visited){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or visited[i][j]==1 or grid[i][j]==0){
            return 0;
        }
        visited[i][j]=1;
        return  1 + dfs(grid,i+1,j,visited) + dfs(grid,i,j+1,visited)+ dfs(grid,i-1,j,visited)+ dfs(grid,i,j-1,visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
        int maxarea = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                maxarea = max(maxarea,dfs(grid,i,j,visited));
            }
        }
        return maxarea;
    }
};
