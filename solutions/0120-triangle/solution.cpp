class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for(int i=1;i<triangle.size();i++){
            vector<int> dp_copy = dp;
            dp_copy.push_back(0);
            for(int j=0;j<triangle[i].size();j++){
                if(j-1>=0 and j<dp.size())
                dp_copy[j]=min(triangle[i][j]+dp[j-1],triangle[i][j]+dp[j]);
                else if(j-1>=0)
                dp_copy[j]=triangle[i][j]+dp[j-1];
                else
                dp_copy[j]=triangle[i][j]+dp[j];
            }
            dp = dp_copy;
        }
        return *min_element(dp.begin(),dp.end());
    }
};
