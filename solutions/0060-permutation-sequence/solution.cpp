class Solution {
public:
int fact(int k) {
    if (k == 0 || k == 1) {
        return 1;
    }
    return k * fact(k - 1);
}

    void solve(set<int>& s,int k,string& ans){
        //take the smallest from set until you exceed count
        if(s.size()==0 or k<=0){
            return ;
        }
        int count = 0;
        int t = s.size()-1;
        int f = fact(t);
        for(auto& item: s){
            if(count+f < k){
                count+= f;
                continue;
            }
            else{
                ans+= to_string(item);
                s.erase(item);
                solve(s,k-count,ans);
                return ;
            }
        }
    }
    string getPermutation(int n, int k) {
        string ans = "";
        set<int> s;
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        solve(s,k,ans);
        return ans;
    }
};
