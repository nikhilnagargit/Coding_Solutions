class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++){
             map<double,int> mp;
            for(int j=i+1;j<n;j++){
                double x1=points[i][0],y1=points[i][1];
                double x2=points[j][0],y2=points[j][1];
                double m=(y2-y1)/(x2-x1);
                if(x1==x2)m=1e10;
                if(mp.count(m))mp[m]++;
                else mp[m]=2;
                ans=max(ans,mp[m]);
            }
        }
        return ans;
    }
};
