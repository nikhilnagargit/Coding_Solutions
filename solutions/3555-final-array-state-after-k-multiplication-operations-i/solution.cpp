class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        int i=0;
        for(auto& n:nums){
            heap.push({n,i});
            i++;
        }
        while(k--){
            auto p = heap.top();heap.pop();
            p.first = p.first*multiplier;
            heap.push(p);
        }
        vector<int> ans(nums.size(),0);
        while(!heap.empty()){
            auto p = heap.top();heap.pop();
            ans[p.second] = p.first;
        }
        return ans;
    }
};
