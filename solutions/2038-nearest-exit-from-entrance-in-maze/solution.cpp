class Solution {
public:
    bool isvalid(int i,int j,int M, int N){
        if(i<0 or j<0 or i>=M or j>=N){
            return false;
        }
        return true;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int M = maze.size();
        int N = maze[0].size();
        vector<int>posi = {0,0,1,-1};
        vector<int>posj = {1,-1,0,0};
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            for( int i=0;i<size;i++){
                pair<int,int> curr = q.front();q.pop();
                if(maze[curr.first][curr.second]=='0'){
                    continue;
                }
                maze[curr.first][curr.second]='0';
                for(int k=0;k<4;k++){
                    int a = curr.first+posi[k];
                    int b = curr.second+posj[k];
                    if(isvalid(a,b,M,N) and maze[a][b]=='.'){
                        q.push({a,b});
                    }
                    else if( isvalid(a,b,M,N) and maze[a][b]=='+'){

                    }
                    else if(!isvalid(a,b,M,N)){
                        if(step==0){

                        }
                        else{
                            return step;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
