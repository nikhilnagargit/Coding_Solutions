class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     vector<vector<int>>v(nums.size(),vector<int>());
     sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++){
         v[i].push_back(nums[i]);
     }

     for(int i=nums.size()-2;i>=0;i--){
         int maxtill = 0;
         int idxtill = -1;
         for(int j=i+1;j<nums.size();j++){
             if(nums[j]%nums[i]==0 and v[j].size()>maxtill){
                 maxtill = v[j].size();
                 idxtill = j;
             }
         }
         if(idxtill!=-1){
             for(auto k:v[idxtill]){
                 v[i].push_back(k);
             }
         }
     }

     int idx  = 0;
     int maxsize = 0;
     for(int i=0;i<nums.size();i++){
         if(maxsize<v[i].size()){
             maxsize= v[i].size();
             idx = i;
         }
     }
     return v[idx];
    }
};
