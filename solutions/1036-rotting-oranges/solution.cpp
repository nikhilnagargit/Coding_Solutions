class Solution {
public:
    bool isvalid(int M,int N, int i,int j){
        if(i<0 or i>=M or j<0 or j>=N){
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh_oranges_count = 0;
        int M = grid.size();
        int N = grid[0].size();
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh_oranges_count++;
                }
            }
        }
        if(fresh_oranges_count==0){
            return 0;
        }
        int converted_count = 0;
        int time = 0 ;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<int,int> curr = q.front();q.pop();
                int a = curr.first;
                int b = curr.second;
                int value = grid[a][b];
                if(value==3){
                    continue;
                }
                grid[a][b] = 3;
                if(value==1){
                    converted_count++;
                }
                if(isvalid(M,N,a+1,b) and grid[a+1][b]!=3 and grid[a+1][b]!=0){
                    q.push({a+1,b});
                }
                if(isvalid(M,N,a,b+1) and grid[a][b+1]!=3 and grid[a][b+1]!=0 ){
                    q.push({a,b+1});
                }
                if(isvalid(M,N,a-1,b) and grid[a-1][b]!=3 and grid[a-1][b]!=0){
                    q.push({a-1,b});
                }
                if(isvalid(M,N,a,b-1) and grid[a][b-1]!=3 and grid[a][b-1]!=0){
                    q.push({a,b-1});
                }
            }
           if(converted_count==fresh_oranges_count){
               return time;
           }
           time++;
        }
        return -1;
    }
};
