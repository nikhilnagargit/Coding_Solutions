class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int>v;
            for(int j=l[i];j<=r[i];j++){
                v.push_back(nums[j]);
            }
            sort(v.begin(),v.end());
            if(v.size()<=2){
                ans.push_back(true);
            }
            else{
                int diff = v[1]-v[0];
                bool flag = true;
                for(int i=2;i<v.size();i++){
                    if(v[i]-v[i-1]!=diff){
                        ans.push_back(false);
                        flag = false;
                        break;
                    }
                }
                if(flag)
                ans.push_back(true);
            }
        }
        return ans;
    }
};
