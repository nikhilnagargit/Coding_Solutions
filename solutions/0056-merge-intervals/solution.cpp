class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int a = ans[ans.size()-1][0];
            int b = ans[ans.size()-1][1];
            int c = intervals[i][0];
            int d = intervals[i][1];
            if(a<=c and c<=b){
                if(d<=b){
                    
                }
                else{
                    ans[ans.size()-1][1]=d;
                }
            }
            else{
                ans.push_back({c,d});
            }
        }
        return ans;
    }
};
