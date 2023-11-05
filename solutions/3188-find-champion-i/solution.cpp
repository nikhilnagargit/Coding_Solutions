class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int count = 0;
        int ans;
        for(int i=0;i<grid.size();i++){
            count =0 ;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
            if(count==grid[0].size()-1){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
