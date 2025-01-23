class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<bool>> processed (grid.size(),vector<bool>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            int row = 0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    row++;
                }
                if(row>1){
                    break;
                }
            }
            if(row>1){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                        count++;
                        processed[i][j] = 1;
                    }
                }
            }
        }
        for(int i=0;i<grid[0].size();i++){
            int col = 0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                    col++;
                }
                if(col>1){
                    break;
                }
            }
            if(col>1){
                for(int j=0;j<grid.size();j++){
                    if(grid[j][i]==1 and processed[j][i]!=1){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
