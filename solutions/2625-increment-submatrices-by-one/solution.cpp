class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n,vector<int> (n,0));
        for(auto& q:queries){
            int i1 = q[0];
            int j1 = q[1];
            int i2 = q[2];
            int j2 = q[3];
            for(int i=i1;i<=i2;i++){
                grid[i][j1]+=1;
                if(j2+1<n)
                grid[i][j2+1]-=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+= grid[i][j-1];
            }
        }
        return grid;
    }
};
