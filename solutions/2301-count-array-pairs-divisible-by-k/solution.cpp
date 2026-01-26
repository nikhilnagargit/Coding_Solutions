class Solution {
public:
    long long gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long count = 0;
        for(int i=0;i<nums.size();i++){
            long long a = gcd(nums[i],k);
            for(auto[key,value]:m){
                if((1LL*gcd(key,k)*a)%k == 0){
                    count+= value;
                }
            }
            m[a]++;
        }
        return count;
    }
};
