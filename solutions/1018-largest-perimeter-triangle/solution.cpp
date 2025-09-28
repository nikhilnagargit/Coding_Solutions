class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans = 0;
        priority_queue<int> heap;
        for(auto& i:nums) heap.push(i);
        int a = heap.top();heap.pop();
        int b= heap.top();heap.pop();
        int c= heap.top();heap.pop();
        while(!heap.empty() and a>=b+c){
            a = b;
            b = c;
            c = heap.top();heap.pop();
        }
        if(a>=b+c){
            return 0;
        }
        return a+b+c;
    }
};
