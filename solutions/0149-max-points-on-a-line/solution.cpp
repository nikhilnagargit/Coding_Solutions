class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int max_count = 1;

        for(int i=0;i<points.size();i++){
            unordered_map<double,int> m;
            for(int j=i+1;j<points.size();j++){
                double slope = 0 ;
                if(points[i][0]-points[j][0]!=0)
                    slope =(points[i][1]-points[j][1])/(1.0*(points[i][0]-points[j][0]));
                else
                    slope = 1e10;
                if(m.find(slope)!=m.end()){
                    m[slope] +=1;
                }
                else{
                    m[slope] = 2;
                }
                max_count = max(max_count,m[slope]);
            }
        }
        return max_count;

    }
};

