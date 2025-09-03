class cmp{
    public:
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            return a[1]>=b[1];
        }
        return false;
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count =0;
        sort(points.begin(),points.end(),cmp());
        for(int i=0;i<points.size();i++){
            int ymax = points[i][1];
            int ymin = INT_MIN;
            for(int j=i+1;j<points.size();j++){
                if(points[j][1]>ymax or points[j][1]<=ymin){
                    continue;
                }
                count++;
                ymin = points[j][1];
            }
        }
        return count;
    }
};
