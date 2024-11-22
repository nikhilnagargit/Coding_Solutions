class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string  s = "";
            int prev = INT_MAX;
            for(int j=0;j<m;j++){
                if(prev!=matrix[i][j]){
                    s+= '|';
                    prev = matrix[i][j];
                }
                else{
                    s+= '*';
                }
            }
            mp[s]++;
        }
        int maxi = 0;
        for(auto item:mp){
            maxi = max(maxi,item.second);
        }
        return maxi;
    }
};
