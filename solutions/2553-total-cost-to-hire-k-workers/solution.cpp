class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int n) {
        priority_queue<int,vector<int>,greater<int>> heap1;
        priority_queue<int,vector<int>,greater<int>> heap2;
        vector<int>h1;
        vector<int>h2;
        int i=0;
        int j=costs.size()-1;
        while(i<=j and i<n){
            if(i<=j){
                heap1.push(costs[i]);
                h1.push_back(costs[i]);
                i++;
            }
            if(i<=j){
                heap2.push(costs[j]);
                h2.push_back(costs[j]);
                j--;
            }
        }

        long long total_cost = 0;
        int N = costs.size();
        for(int m=0;m<k;m++){
            if(heap1.size()==0 and heap2.size()==0){
                break;
            }
            else if(heap1.size()==0){
                total_cost+= heap2.top();
                heap2.pop();
            }
            else if(heap2.size()==0){
                total_cost+=heap1.top();
                heap1.pop();
            }
            else if(heap1.top()>heap2.top()){
                total_cost+= heap2.top();
                heap2.pop();
                if(i<=j){
                    heap2.push(costs[j]);
                    j--;
                }
            }
            else if(heap1.top()<=heap2.top()){
                total_cost+= heap1.top();
                heap1.pop();
                if(i<=j){
                    heap1.push(costs[i]);
                    i++;
                }
            }
        }
        return total_cost;
    }
};
