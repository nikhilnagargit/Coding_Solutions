class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int considered = 0;
        int arrow_count =0;
        sort(points.begin(),points.end());
        int i=0;
        while(considered<points.size()){
            arrow_count+=1;
            int start = points[considered][0];
            int end = points[considered][1];
            i= considered+1;
            while(i<points.size() and points[i][0]<=end){
                end = min(end,points[i][1]);
                i++;
            }
            considered = i;
        }
        return arrow_count;
    }
};
