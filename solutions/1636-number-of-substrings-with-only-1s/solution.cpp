class Solution {
public:
    int numSub(string s) {
        if(s.size()==0) return 0;
        long long ans = 0;
        int mod = 1000000007;
        long long count = 0;
        if(s[0]=='1') count++;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                ans+= ((count*(count+1))/2)%mod;
                count = 0;
            }
        }
        ans+= ((count*(count+1))/2)%mod;
        return ans;

    }
};
