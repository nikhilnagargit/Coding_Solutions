class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // make the map and store counts
        unordered_map<int,int>m;
        for(auto& i:arr){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(auto item:m){
            v.push_back({item.second,item.first});
        }
        sort(v.begin(),v.end());
        int i=0;
        int ans = v.size();
        for(int i=0;i<v.size();i++){
            if(v[i].first<=k){
                k = k-v[i].first;
                ans--;
            }
            else{
                k = 0;
                break;
            }
        }
        return ans;
    }
};
