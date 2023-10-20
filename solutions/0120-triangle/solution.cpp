class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev;
        vector<int> curr;
        prev.push_back(triangle[0][0]);

        if(triangle.size()==0){
            return 0;
        }
        if(triangle.size()==1){
            return triangle[0][0];
        }

        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0)
                curr.push_back(triangle[i][j]+prev[j]);
                else if(j==triangle[i].size()-1)
                curr.push_back(triangle[i][j]+prev[j-1]);
                else
                curr.push_back(triangle[i][j]+min(prev[j-1],prev[j]));
            }
            prev = curr;
            curr.clear();
        }
        
        // return minimum from prev
        int mini = INT_MAX;
        for(int i=0;i<prev.size();i++){
            mini = min(mini,prev[i]);
        }
        return mini;
    }
};
