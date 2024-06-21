class Solution {
public:


    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<vector<bool>> visited(N,vector<bool>(M,0));
        queue<pair<int,int>> q;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int counter = 0;
int flag = 1;
             for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(grid[i][j]==1){
                            flag = 0;
                        }
                    }
                }

if(flag==1){
    return 0;
}
        while(!q.empty()){

             //check if complete grid is rotten
                int flag = 1;
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(grid[i][j]==1){
                            flag = 0;
                        }
                    }
                }
                if(flag == 1){
                    return counter;
                }

            int s = q.size();

            for(int k=0;k<s;k++){
                pair<int,int> p = q.front();q.pop();
                if(visited[p.first][p.second]){
                    continue;
                }
                visited[p.first][p.second]= 1;
                int i = p.first;
                int j = p.second;
                if(i+1<N and  grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    if(!visited[i+1][j]){
                        q.push({i+1,j});
                    }
                }
                if(j+1<M and grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    if(!visited[i][j+1]){
                        q.push({i,j+1});
                    }
                }
                if(i-1>=0 and  grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    if(!visited[i-1][j]){
                        q.push({i-1,j});
                    }
                }
                if(j-1>=0 and grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    if(!visited[i][j-1]){
                        q.push({i,j-1});
                    }
                }

            }

             counter++;
               
        }
        return -1;

    }
};
