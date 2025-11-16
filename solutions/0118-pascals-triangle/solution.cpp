class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int> temp;
        for(int i=1;i<=numRows;i++){
            //create a vector of i size with all elements one
            vector<int> v(i,1);
            for(int j=1;j<temp.size();j++){
                v[j]=temp[j]+temp[j-1];
            }
            temp = v;
            ans.push_back(temp);
        }
        return ans;
    }
};
