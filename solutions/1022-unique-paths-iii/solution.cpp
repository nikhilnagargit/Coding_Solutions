class Solution {
public:
    
    bool is_safe(int i,int j,vector<vector<int>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==-1){
            return false;
        }
        return true;
    }
    
    
    int solve(int i,int j, int x,int y ,vector<vector<int>>& grid,int visited[21][21],int count,int target_count){
        if(i==x and j==y and count==target_count){

            return 1;
        }

        int one=0 ,two=0,three=0,four=0;
        
        if(is_safe(i,j+1,grid) and visited[i][j+1]==false){
            visited[i][j+1] = true;
            one = solve(i,j+1,x,y,grid,visited,count+1,target_count);
            visited[i][j+1] = false;
        }
        if(is_safe(i+1,j,grid)  and visited[i+1][j]==false){
            visited[i+1][j] = true;
            two = solve(i+1,j,x,y,grid,visited,count+1,target_count);
            visited[i+1][j] = false;
        }
        if(is_safe(i-1,j,grid)  and visited[i-1][j]==false){
            visited[i-1][j] = true;
            three = solve(i-1,j,x,y,grid,visited, count+1,target_count);
            visited[i-1][j] = false;
        }
        if(is_safe(i,j-1,grid)  and visited[i][j-1]==false){
            visited[i][j-1] = true;
            four = solve(i,j-1,x,y,grid,visited, count+1,target_count);
            visited[i][j-1] = false;
        }
        
        return one+two+three+four;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int visited[21][21]= {{0}};
        
        int target_count = 0;
        int start_x,start_y,end_x,end_y;
        
//      find the start
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                    target_count++;
                }
                
                if(grid[i][j]==2){
                    end_x = i;
                    end_y = j;
                    target_count++;
                }
                
                if(grid[i][j]==0){
                    target_count++;
                }
            }
        }
        
        
        visited[start_x][start_y] = true;
        
        return solve(start_x,start_y,end_x,end_y,grid,visited,1,target_count);
        
        
        
        
    }
};
