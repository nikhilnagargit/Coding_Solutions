class Solution {
public:

    void printboard(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<", ";
            }
            cout<<endl;
        }

        cout<<"-----------------"<<endl;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        // 0 = unguarded  , 1 = guard,  2 = wall ,  3 = guarded
        for(auto& g: guards){
            grid[g[0]][g[1]] = 1;
        }
        for(auto& w:walls){
            grid[w[0]][w[1]] = 2;
        }

        //passes
        bool guardingActive = 0;
        //left to right
        for(int i=0;i<m;i++){
            guardingActive = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    guardingActive = 1;
                }
                else if(grid[i][j]==2){
                    guardingActive = 0;
                }
                else{
                    if(guardingActive)
                    grid[i][j] = 3;
                }
            }
        }

        // printboard(grid);
        //right to left
      
        for(int i=0;i<m;i++){
            guardingActive = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    guardingActive = 1;
                }
                else if(grid[i][j]==2){
                    guardingActive = 0;
                }
                else{
                    if(guardingActive)
                    grid[i][j] = 3;
                }
            }
        }
//    printboard(grid);
        //top to down

        for(int j=0;j<n;j++){
            guardingActive = 0;
          for(int i=0;i<m;i++){
                if(grid[i][j]==1){
                    guardingActive = 1;
                }
                else if(grid[i][j]==2){
                    guardingActive = 0;
                }
                else{
                    if(guardingActive)
                    grid[i][j] = 3;
                }
            }
        }

//    printboard(grid);
        //down to top
      
        for(int j=0;j<n;j++){
            guardingActive = 0;
            for(int i=m-1;i>=0;i--){
                if(grid[i][j]==1){
                    guardingActive = 1;
                }
                else if(grid[i][j]==2){
                    guardingActive = 0;
                }
                else{
                    if(guardingActive)
                    grid[i][j] = 3;
                }
            }
        }
//    printboard(grid);
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }

        return count;

    }
};
