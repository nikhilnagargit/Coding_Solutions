class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> previous(201,INT_MAX);
        vector<int> current(201,INT_MAX);
        previous[0] = triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<=i;j++){
                if(j-1>=0 and j<i){
                    current[j] = triangle[i][j] + min(previous[j-1],previous[j]);
                }
                else if(j-1>=0){
                    current[j] = triangle[i][j] + previous[j-1];
                }
                else{
                    current[j] = triangle[i][j] + previous[j];
                }
                
            }
            for(int j=0;j<=i;j++){
                previous[j] = current[j];
            }
        }
        
        return *min_element(previous.begin(),previous.end());
        
    }
};
