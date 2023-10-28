class Solution {
public:
    int countVowelPermutation(int n) {
        long long MOD=1e9+7;
        map<char,vector<char>> rules;
        rules['a']=vector<char>{'e'};
        rules['e']=vector<char>{'a','i'};
        rules['i']=vector<char>{'a','e','o','u'};
        rules['o']=vector<char>{'i','u'};
        rules['u']=vector<char>{'a'};
        // rules[""] = vector<string>{"a","e","i","o","u"};

        map<char,vector<long>> dp;
        dp['a'] = vector<long>(n+1,0);
        dp['e'] = vector<long>(n+1,0);
        dp['i'] = vector<long>(n+1,0);
        dp['o'] = vector<long>(n+1,0);
        dp['u'] = vector<long>(n+1,0);

        string temp = "aeiou";
        for(auto i:temp){
            dp[i][1]=1;
        }
        long sum  = 0;
        for(int k=2;k<=n;k++){
            for(auto i:temp){
                for(auto j:rules[i]){
                    dp[j][k]=(dp[j][k]%MOD+dp[i][k-1]%MOD)%MOD;
                }
            }
        }
        for(auto i:temp){
            sum= (sum%MOD + dp[i][n])%MOD;
        }
        return sum%MOD;
        
    }

 

};
