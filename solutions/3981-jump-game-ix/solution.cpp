class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        stack<pair<int,int>> stk;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            //if stack empty
            if(stk.empty()){
                stk.push({i,nums[i]});
            }
            else{
                //stack not empty
                //if nums[i] is > max of top
                if(nums[i]>=stk.top().second){
                    //new range insert and move on
                    stk.push({i,nums[i]});
                }
                else{
                    // start popping out until the stk top is greater than curr value
                    pair<int,int> p;
                    while(!stk.empty() and stk.top().second>nums[i]){
                        auto temp = stk.top();stk.pop();
                        p.first = temp.first;
                        p.second = max(p.second,temp.second);
                    }
                    //push again in stack
                    stk.push(p);
                }
            }
        }


        //pop everthing from stack and push the max values;
        int start = nums.size()-1;
        while(!stk.empty()){
            auto p = stk.top();stk.pop();
             for(int i=start;i>=p.first;i--){
                 ans[i]=p.second;
             }
            start = p.first-1;
        }
       return ans;
    }
};
