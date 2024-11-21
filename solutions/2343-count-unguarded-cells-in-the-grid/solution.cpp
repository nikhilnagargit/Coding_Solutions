class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> arr(m,vector<int>(n,0));

        //2 = wall
        //3 = guard
        int total = m*n - walls.size() - guards.size();

        for(auto& i:walls){
            arr[i[0]][i[1]] = 2;
        }
        for(auto& i:guards){
            arr[i[0]][i[1]] = 3;
        }

        for(auto& g:guards){

            int i = g[0];
            int j = g[1];
            //up
            for(int k=i-1;k>=0;k--){
                if(arr[k][j]==2 or arr[k][j]==3){
                    break;
                }
                else if(arr[k][j]==0){
                    arr[k][j] = 1;
                    total--;
                }
            }

            //left
            for(int k=j-1;k>=0;k--){
                if(arr[i][k]==2 or arr[i][k]==3){
                    break;
                }
                else if(arr[i][k]==0){
                    arr[i][k] = 1;
                    total--;
                }
            }

            //right
            for(int k=j+1;k<n;k++){
                if(arr[i][k]==2 or arr[i][k]==3){
                    break;
                }
                else if(arr[i][k]==0){
                    arr[i][k] = 1;
                    total--;
                }
            }
            //down
            for(int k=i+1;k<m;k++){
                if(arr[k][j]==2 or arr[k][j]==3){
                    break;
                }
                else if(arr[k][j]==0){
                    arr[k][j] = 1;
                    total--;
                }
            }

        }


        // int count = 0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(arr[i][j]==0){
        //             count++;
        //         }
        //     }
        // }
        return total;
    }
};
