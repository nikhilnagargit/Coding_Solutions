class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {};
        vector<int> currRow = {};

        for(int i=0;i<numRows;i++){
            vector<int> newRow = currRow;
            newRow.push_back(1);
            for(int j=0;j+1<(currRow.size());j++){
                newRow[j+1] = currRow[j]+currRow[j+1];
            }
            ans.push_back(newRow);
            currRow = newRow;
        }
        return ans;
    }
};
