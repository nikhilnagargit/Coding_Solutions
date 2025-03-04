class Solution {
public:
    unordered_map<int,long long>m;
    unordered_map<string,bool> mp;

    bool solve(int n,int power){
        if(n<0){
            return false;
        }
        if(n==0){
            return true;
        }
        string s = "";
        s+= to_string(n)+"-"+to_string(power);

        if(mp.find(s)!=mp.end()){
            return mp[s];
        }

        int curr =0;
        if(m.find(power) != m.end()){
            curr=m[power];
        }
        else{
            m[power] = pow(3,power);
            curr = m[power];
        }
        if(curr>n){
            return false;
        }
        return mp[s]=(solve(n-curr,power+1) or solve(n,power+1));
    }

    bool checkPowersOfThree(int n) {
        return solve(n,0);
    }
};
