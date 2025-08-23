class Solution {
public:
    vector<vector<int>> rotateClockwise(vector<vector<int>> grid){
        vector<vector<int>> v(grid[0].size(),vector<int>(grid.size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                v[j][grid.size()-i-1] = grid[i][j];
            }
        }
        return v;
    }

    int findMinimumAreaof1s (vector<vector<int>>& grid, int a,int b, int c, int d){
        int top = INT_MAX;
        int left = INT_MAX;
        int right = INT_MIN;
        int bottom = INT_MIN;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                if(grid[i][j]==1){
                    top = min(top,i);
                    left = min(left,j);
                    right = max(right,j);
                    bottom = max(bottom,i);
                }
            }
        }
        if(top==INT_MAX) return 0;
        return (bottom-top+1)*(right-left+1);
    }

    int solve(vector<vector<int>>& grid){
        //make 3 cases;

        //first case
        int ans1 = INT_MAX;
        for(int a=0;a<grid.size()-2;a++){
            for(int b= grid.size()-1;b>=2;b--){
                // first area
                int a1 = findMinimumAreaof1s(grid,0,0,a,grid[0].size()-1);
                //second area
                int a2= findMinimumAreaof1s(grid,a+1,0,b-1,grid[0].size()-1);
                //third area
                int a3 = findMinimumAreaof1s(grid,b,0,grid.size()-1,grid[0].size()-1);
                ans1 = min(ans1,a1+a2+a3);
            }
        }

        //second case
        int ans2 = INT_MAX;
        for(int a=grid.size()-1;a>=1;a--){
            for(int b=0;b<grid[0].size()-1;b++){
                // first area
                int a1 = findMinimumAreaof1s(grid,0,0,a-1,b);
                //second area
                int a2= findMinimumAreaof1s(grid,0,b+1,a-1,grid[0].size()-1);
                //third area
                int a3 = findMinimumAreaof1s(grid,a,0,grid.size()-1,grid[0].size()-1);
                cout<<a1<<", "<<a2<<", "<<a3<<endl;
                ans2 = min(ans2,a1+a2+a3);
            }
        }

        // third case
        int ans3 = INT_MAX;
        for(int a = 0;a<grid.size()-1;a++){
            for(int b=1;b<grid[0].size()-1;b++){
                // first area
                int a1 = findMinimumAreaof1s(grid,0,0,a,grid[0].size()-1);
                //second area
                int a2= findMinimumAreaof1s(grid,a+1,0,grid.size()-1,b);
                //third area
                int a3 = findMinimumAreaof1s(grid,a+1,b+1,grid.size()-1,grid[0].size()-1);
                ans3 = min(ans3,a1+a2+a3);
            }
        }
        // cout<<ans1<<", "<<ans2<<", "<<ans3<<", ";
        return min({ans1,ans2,ans3});
    }

    int minimumSum(vector<vector<int>>& grid) {
        vector<vector<int>> newv = rotateClockwise(grid);
        return min(solve(grid), solve(newv));
    }
};
