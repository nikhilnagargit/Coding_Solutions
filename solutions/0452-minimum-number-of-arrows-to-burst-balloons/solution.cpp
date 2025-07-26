class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int ans = 0;

        vector<int> curr = points[0];

        for(int i=1;i<points.size();i++){
            vector<int> next = points[i];
            if(curr[1]>=next[0]){
                curr = {curr[0],min(curr[1],next[1])};
            }
            else{
                ans++;
                curr = next;
            }
        }
        ans++;
        return ans;
    }
};
