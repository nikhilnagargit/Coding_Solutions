class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>> heap;
        sort(intervals.begin(),intervals.end());
        for(auto&i: intervals){
            if(heap.empty() or heap.top()>=i[0]){
                heap.push(i[1]);
            }
            else{
                heap.pop();
                heap.push(i[1]);
            }
        }
        return heap.size();
    }
};
