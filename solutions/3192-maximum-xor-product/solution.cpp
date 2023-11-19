class Solution {
public:
    #define ll long long
    const int mod = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        ll temp = 1;
        for(ll i = n-1;i >= 0;i--){
            if((a&(temp << i)) == 0 and (b&(temp <<i)) == 0){
                a += (temp<<i);
                b += (temp <<i);
                continue;
            }         
            if(a > b){
                if((b&(temp << i)) == 0){
                    b +=(temp<<i);
                    a -= (temp << i);
                }
            }else{
                if((a&(temp << i)) == 0){
                    a += (temp<<i);
                    b-=(temp<<i);
                }
            }
        }
        a %= mod;
        b %= mod;
        return (1ll*a*b)%mod;
    }
};
