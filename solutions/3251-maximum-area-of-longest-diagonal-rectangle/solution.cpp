class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        int a = d[0][0];
        int b = d[0][1];
        double c = sqrt(a*a*1.0 + b*b);
        for(int i=0;i<d.size();i++){
            double c1 = sqrt(d[i][0]*d[i][0]*1.0 + d[i][1]*d[i][1]);
            if(c1>c){
                c = c1;
                a = d[i][0];
                b = d[i][1];
            }
            else if(c1==c){
                if(a*b > d[i][0]*d[i][1]){
                    
                }
                else{
                    c = c1;
                    a = d[i][0];
                    b = d[i][1];
                }
            }
        }
        return a*b;
    }
};
