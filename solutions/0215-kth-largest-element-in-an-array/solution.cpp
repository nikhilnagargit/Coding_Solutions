class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(auto i:nums) heap.push(i);
        k--;
        while(k--){
            heap.pop();
        }
        return heap.top();
    }
};
