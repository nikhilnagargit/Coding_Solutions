class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int mod = 1000000007;
        int count =0 ;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        int i=0;
        int maxlimit = -1;
        while(i<nums.size()){
            if(i<maxlimit){
                maxlimit = max(maxlimit,m[nums[i]]);
            }
            else if(i==maxlimit){
                count++;
            }
            else if(m[nums[i]]==i){
                count++;
            }
            else{
                maxlimit = max(maxlimit,m[nums[i]]);
            }
            i++;
        }
 
        if(count==0){
            return 1;
        }
        int ans = 1;
        for(int i=1;i<count;i++){
            ans = (ans*2)%mod;
        }
        return ans;
    }
};
