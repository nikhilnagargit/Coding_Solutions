class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(auto& s:stones){
            heap.push(s);
        }
        while(heap.size()>=2){
            int a = heap.top();heap.pop();
            int b = heap.top();heap.pop();
            if(a==b){
                continue;
            }
            else if(a>b){
                heap.push(a-b);
            }
            else{
                heap.push(b-a);
            }
        }
        if(heap.size()==0) return 0;
        return heap.top();
    }
};
