class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> max_heap;
        long long total = 0;
        for(auto& g:gifts){
            max_heap.push(g);
            total = total+g;
        }
        while(k--){
            long long top = max_heap.top();max_heap.pop();
            long long  s = sqrt(top);
            max_heap.push(s);
            total = total - top + s;
        }
        return total;
    }
};
