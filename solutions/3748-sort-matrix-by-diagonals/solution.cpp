class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> diags;
        int n = grid.size();
        //get the items
        for(int diag = 0;diag<(2*n-1);diag++){
            int i = max(n-1-diag,0);
            int j = max(diag-n+1,0);
            vector<int> temp;
            //go till one of them get invalid
            for(int a=i,b=j;a<n and b<n; a++,b++){
                temp.push_back(grid[a][b]);
            }
            diags.push_back(temp);
        }
        //sort the items
        //first n items in increasing order
        for(int i=0;i<n;i++){
            sort(diags[i].begin(),diags[i].end(),greater<int>());
        }
        for(int i=n;i<2*n-1;i++){
            sort(diags[i].begin(),diags[i].end());
        }

        //put the items back
        for(int diag = 0;diag<(2*n-1);diag++){
            int i = max(n-1-diag,0);
            int j = max(diag-n+1,0);
            //go till one of them get invalid
            for(int a=i,b=j,k=0;a<n and b<n; a++,b++,k++){
                grid[a][b] = diags[diag][k];
            }
        }
        return grid;
    }
};
