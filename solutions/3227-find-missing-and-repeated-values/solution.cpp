class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a = 0;
        int b = 0;
        unordered_set<int> s;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(s.count(grid[i][j])!=0){
                    a = grid[i][j];
                    s.insert(grid[i][j]);
                }
                else{
                    s.insert(grid[i][j]);
                }
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(s.count(i)==0){
                b = i;
                break;
            }
        }
        return vector<int> {a,b};
    }
};
