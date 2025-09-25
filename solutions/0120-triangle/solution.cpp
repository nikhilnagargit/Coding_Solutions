class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for(int row=1;row<triangle.size();row++){
            vector<int> temp = dp;
            temp.push_back(0);
            for(int i=0;i<triangle[row].size();i++){
                //find two parent's indexes from where we can come here
                int idx1 = i;
                int idx2 = i-1;
                
                //put the value in new dp row
                int value1 = INT_MAX/2;
                int value2 = INT_MAX/2;

                if(idx1<dp.size()){
                    value1 = dp[idx1];
                }
                if(idx2>=0){
                    value2 = dp[idx2];
                }
                temp[i] = triangle[row][i] + min({value1,value2});
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for(auto& i:dp){
            mini = min(mini,i);
        }
        return mini;
    }
};
