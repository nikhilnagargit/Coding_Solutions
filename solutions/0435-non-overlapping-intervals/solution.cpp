class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)return 0;
        sort(intervals.begin(),intervals.end());
        vector<int>prev = intervals[0];
        int removed =0;
        for(int i=1;i<intervals.size();i++){

            if(prev[1]<=intervals[i][0]){
                prev = intervals[i];
            }
            else if(prev[1]>intervals[i][0] and prev[1]<intervals[i][1]){
                removed++;
            }
            else{
                removed++;
                prev = intervals[i];
            }
        }
        return removed;
    }
};
