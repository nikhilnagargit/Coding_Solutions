class Solution {
public:

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            int n = items.size();
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        vector<int> maxiUpto(n); // the maximum beauty upto index i in the sorted items array 
        
        maxiUpto[0] = items[0][1];
        
        for(int i=1;i<n;i++){
            maxiUpto[i] = max(maxiUpto[i-1], items[i][1]);
        }

        vector<int> ans;
        for(auto q : queries){
            vector<int> temp = {q,INT_MAX};
            auto iter = upper_bound(items.begin(), items.end(), temp) - items.begin();
            iter--;
            if(iter<0)
                ans.push_back(0);
            else{
                ans.push_back(maxiUpto[iter]);

            }
        }
        return ans;
    }
};
