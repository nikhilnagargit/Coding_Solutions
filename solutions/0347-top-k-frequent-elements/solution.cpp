class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto& n:nums){
            m[n]++;
        }
        priority_queue<pair<int,int>> max_heap;

        for(auto& item:m){
            max_heap.push({item.second,item.first});
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return ans;
    }
};
