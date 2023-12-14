class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
                int M= grid.size();
        int N = grid[0].size();
        vector<int>numofOnesRowWise(M,0);
        vector<int>numofOnesColWise(N,0);
        vector<vector<int>> ans(M,vector<int>(N,0));

        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==1){
                    numofOnesRowWise[i]++;
                    numofOnesColWise[j]++;
                }
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                ans[i][j] = 2*(numofOnesRowWise[i]+numofOnesColWise[j])-N-M;
            }
        }
        return ans;
    }
};
