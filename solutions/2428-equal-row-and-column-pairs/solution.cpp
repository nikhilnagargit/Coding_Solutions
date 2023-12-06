class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int>m_row,m_col;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            string s= "";
            for(int j=0;j<n;j++){
                s+= to_string(grid[i][j])+"-";
            }
            m_row[s]++;
        }
        for(int i=0;i<n;i++){
            string s= "";
            for(int j=0;j<m;j++){
                s+= to_string(grid[j][i])+"-";
            }
            m_col[s]++;
        }
        int ans  = 0;
        for(auto item:m_col){
            string key = item.first;
            ans+= m_row[key]*m_col[key];
        }
        return ans;
    }
};
