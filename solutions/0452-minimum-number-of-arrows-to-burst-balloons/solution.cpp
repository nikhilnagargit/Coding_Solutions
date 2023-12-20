class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int curr_end = points[0][1];
        int count=1;
        int i=1;
        while(i<points.size()){
            if(points[i][0]<=curr_end){
                curr_end = min(points[i][1],curr_end);
                i++;
            }
            else{
                curr_end = points[i][1];
                count++;
                i++;
            }
        }
        return count;
    }
};
