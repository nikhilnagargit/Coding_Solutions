class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;
        for(int right=0;right<nums.size();right++){
            //remove invalids
            while(!dq.empty() and (dq.front().first)<=(right-k)){
                dq.pop_front();
            }
            //remove until smaller elements from end
            int curr = nums[right];
            while(!dq.empty() and dq.back().second<=curr){
                dq.pop_back();
            }
            //insert the curr
            dq.push_back({right,curr});

            //push in asnwer
            if(right>=k-1){
                ans.push_back(dq.front().second);
            }
        }
        return ans;
    }
};
