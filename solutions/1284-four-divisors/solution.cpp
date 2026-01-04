class Solution {
public:
    int findSum(int n){
        int count = 0;
        int sum = 1+n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(i==n/i){
                    count+=1;
                    sum+=i;
                }
                else{
                count+=2;
                sum+=i;
                sum+=n/i;
                }
            }
            if(count>2){
                return 0;
            }
        }
        if(count<2) return 0;
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for(auto n:nums){
            m[n]++;
        }
        for(auto item: m){
            ans += findSum(item.first)*item.second;
        }
        return ans;
    }
};
