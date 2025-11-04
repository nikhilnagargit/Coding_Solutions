class Solution {
public:

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for(int i=0;i<nums.size()-k+1;i++){
            unordered_map<int,int> freq;
            for(int j=i;j<i+k;j++){
                freq[nums[j]]++;
            }
            vector<pair<int,int>> v;
            for(auto item: freq){
                v.push_back({item.second,item.first});
            }
            sort(v.begin(),v.end(),greater<pair<int,int>>());
            int s = v.size();
            int P = min(x,s);
            int sum = 0 ;
            for(int t=0;t<P;t++){
               sum+= v[t].first*v[t].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
