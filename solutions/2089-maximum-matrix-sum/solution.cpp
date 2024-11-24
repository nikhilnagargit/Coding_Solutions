class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX;
        int negCount = 0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mini =min(mini,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    negCount++;
                }
                sum+= abs(matrix[i][j]);
            }
        }

        if(negCount%2==0){
            return sum;
        }
        return sum - 2*mini;

    }
};
