class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<long long> v;
        for(auto item:values){
            for(auto subitem:item){
                v.push_back(subitem);
            }
        }
        long long ans=0;
        sort(v.begin(),v.end());
        for(long long i=0;i<v.size();i++){
            ans+= (i+1)*v[i];
        }
        return ans;
    }
};
