class Cmp{
   public:
     bool operator()(vector<int>& a, vector<int>& b) const{
        if(a[0]>b[0]){
            return true;
        }
        else if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return false;
     }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),Cmp());
        // for(auto p:points){
        //     cout<<p[0]<<","<<p[1]<<" |  ";
        // }
        int count = 0;
        for(int i=0;i<points.size();i++){
            //select a point
            int x = points[i][0];
            int y = points[i][1];
            for(int j=i+1;j<points.size();j++){
                //select second point
                int x1 = points[j][0];
                int y1 = points[j][1];

                //check if second point is top left
                if(x1>x or y1<y) continue;
                //make a range witt top left side points
                int xlow = min(x,x1);
                int ylow = min(y1,y);
                int xhigh = max(x,x1);
                int yhigh = max(y1,y);

                //check if anyother point exists in this range except these two
                int flag = 1;
                for(int k=0;k<points.size();k++){
                    if(k==i or k==j){
                        continue;
                    }
                    int x2 = points[k][0];
                    int y2 = points[k][1];
               
                    //check range
                    if(x2>=xlow and x2<=xhigh and y2>=ylow and y2<=yhigh){
                        flag = 0;
                        break;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
};
