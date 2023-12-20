class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> stk;
        vector<int>ans(t.size(),0);
        for(int i=t.size()-1;i>=0;i--){
            while(!stk.empty() and stk.top().first<=t[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top().second-i;
            }
            stk.push({t[i],i});
        }
        return ans;
    }
};
