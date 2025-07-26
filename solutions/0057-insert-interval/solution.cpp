class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<int> prev = intervals[0];

        for(int i=1;i<intervals.size();i++){

            vector<int> curr = intervals[i];
            if(prev[1]>=curr[0]){
                prev = {prev[0],max(prev[1],curr[1])};
            }
            else{
                ans.push_back(prev);
                prev = curr;
            }

        }
        ans.push_back(prev);

        return ans;
    }
};
