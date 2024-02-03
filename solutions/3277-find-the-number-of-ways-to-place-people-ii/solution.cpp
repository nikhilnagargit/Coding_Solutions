class Solution {
public:
bool isvalid(vector<vector<int>>&points, int I,int J){
        int x1= points[I][0];
        int y1= points[I][1];
        int x2= points[J][0];
        int y2= points[J][1];
        
        if(x1==x2 or y1==y2){
            
        }
        else if(x1<x2){
            if(y1>=y2){
            
            }
            else{
                return false;
            }
        }
        else{
            if(y1>y2){
                return false;
            }
        }
                       
        for(int i=0;i<points.size();i++){
            if(i!=I and i!=J){
                int a = points[i][0];
                int b = points[i][1];
                int X  = abs(x2-x1);
                int Y  = abs(y2-y1);
                int dis_ax1 = abs(x1-a);
                int dis_ax2 = abs(x2-a);
                int dis_by1 = abs(y1-b);
                int dis_by2 = abs(y2-b);
                if(dis_ax1<=X and dis_ax2<=X and dis_by1<=Y and dis_by2<=Y){
                    return false;
                }
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                
                if(isvalid(points,i,j))
                    ans++;
            }
        }
        return ans;
    }
};
