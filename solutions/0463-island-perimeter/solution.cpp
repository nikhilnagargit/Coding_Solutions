class Solution {
public:

    int countWaterSides(int i,int j, vector<vector<int>>& grid){
        int count = 0;
        if(i-1>=0 and grid[i-1][j]==0){
            count++;
        }
        else if(i-1<0){
            count++;
        }
        
        if(j-1>=0 and grid[i][j-1]==0){
            count++;
        }
        else if(j-1<0){
            count++;
        }
        if(i+1<grid.size() and grid[i+1][j]==0){
            count++;
        }
                else if(i+1>=grid.size()){
            count++;
        }
        if(j+1<grid[0].size() and grid[i][j+1]==0){
            count++;
        }
          else if(j+1>=grid[0].size()){
            count++;
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0 ;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    perimeter += countWaterSides(i,j,grid);
                }
            }
        }
        return perimeter;
    }
};
