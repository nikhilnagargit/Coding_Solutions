class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0 ;
        unordered_map<int,int> m;
        m[0]=1;
        int sum = 0 ;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            // if the sum-target is already seen, then that can be added in result
            if(m.find(sum-k)!=m.end()){
                result+= m[sum-k];
                
            }
            m[sum]++;

        }
        return result;
    }
};
