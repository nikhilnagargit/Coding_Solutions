class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> numst(s.begin(),s.end());
        priority_queue<int> heap;
        for(auto& num:numst){
            heap.push(num);
        }
        vector<int>ans;
        while(k-- and !heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};
