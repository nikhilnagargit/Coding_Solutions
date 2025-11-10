class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s;
        int count = 0;
        for(auto& n: nums){
            while(!s.empty() and s.top()>n){
                s.pop();
            }
            if(n==0) continue;
            if(s.empty() or s.top()<n){
                s.push(n);
                count++;
            }
        }
        return count;
    }
};
