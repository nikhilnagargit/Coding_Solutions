class Solution {
public:
    int sum_of_digits(int i){
        int sum = 0;
        while(i){
            int suffix = i%10;
            sum+=suffix;
            i = i/10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> m;
        for(int& i:nums){
            m[sum_of_digits(i)].push(i);
        }
        int max_sum = -1;
        for(auto heap:m){
            if(heap.second.size()>=2){
                int candidate = heap.second.top();
                heap.second.pop();
                candidate += heap.second.top();
                max_sum = max(max_sum,candidate);
            }
        }
        return max_sum;
    }
};
