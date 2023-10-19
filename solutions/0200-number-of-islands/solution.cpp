class Solution {
public:

    void color(vector<vector<char>>& grid,int i,int j){
        if(i>=grid.size() or i<0 or j<0 or j>=grid[0].size()){
            return;
        }
        if(grid[i][j]=='0' or grid[i][j]=='2'){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j] = '2';
        }
        color(grid,i,j+1);
        color(grid,i,j-1);
        color(grid,i+1,j);
        color(grid,i-1,j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count_of_color_initiation =0;

        // find 1 and start coloring(negative 1)
        int i=0;
        int j=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    color(grid,i,j);
                    count_of_color_initiation++;
                }
            }
        }

        return count_of_color_initiation;
    }
};
