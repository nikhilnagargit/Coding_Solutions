class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<int> starttime;
        vector<int> endtime;
        for(auto item:intervals){
            starttime.push_back(item[0]);
            endtime.push_back(item[1]);
        }
         intervals.clear();
        vector<vector<int>> ans;
        
        sort(starttime.begin(),starttime.end());
        sort(endtime.begin(),endtime.end());
        
        int start=0;
        int i=1;
        while(i<starttime.size()){
            if(endtime[i-1]>=starttime[i]){
                i++;
            }
            else{
                ans.push_back(vector<int>{starttime[start],endtime[i-1]});
                start=i;
                i++;
            }
        }
        ans.push_back(vector<int>{starttime[start],endtime[i-1]});
        starttime.clear();
        endtime.clear();
        return ans;


    }
};
