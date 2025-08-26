class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxarea = 0;
        int maxdiag = 0;
        for(auto& d:dimensions){
            int diag = d[0]*d[0] + d[1]*d[1];
           if(maxdiag < diag){
                maxarea = d[0]*d[1];
                maxdiag = diag;
           }
           else if(maxdiag==diag and maxarea<d[0]*d[1]){
                maxarea = d[0]*d[1];
           }
        }
        return maxarea;
    }
};
