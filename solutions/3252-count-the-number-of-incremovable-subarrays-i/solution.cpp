class Solution {
public:
    bool check(vector<int>& nums,int left,int right){
        
        vector<int>v ;
        for(int i=0;i<nums.size();i++){
            if(i<left or i>right){
                v.push_back(nums[i]);
            }
        }
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]){
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans =0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
             if(check(nums,i,j)){
                 ans++;
             }   
            }
        }
        return ans;
    }
};
