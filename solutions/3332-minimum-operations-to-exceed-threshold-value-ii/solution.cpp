class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>heap;
        for(auto& n:nums){
            heap.push(n);
        }
        int count = 0;
        while(heap.top()<k){
            long long a = heap.top();heap.pop();
            long long b = heap.top();heap.pop();
            heap.push(min(a,b)*2 + max(a,b));
            count++;
        }
        return count;
    }
};
