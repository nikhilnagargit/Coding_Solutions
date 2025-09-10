
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //sort the interval (a,b) => a1<a2 and b1<b2

        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        vector<int> ans(queries.size(),-1);

        int i=0;
        for(auto& item:v){
            int q = item.first;
            int qindex = item.second;

   
            while(i<intervals.size() and q>=intervals[i][0]){
                min_heap.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }

            //pop from heap until q in range of top of heap
            while(!min_heap.empty() and min_heap.top().second<q){
                min_heap.pop();
            }

            //pop the top 
            if(!min_heap.empty()){
            ans[qindex] = min_heap.top().first;
            }

        }
        return ans;
    }
};

