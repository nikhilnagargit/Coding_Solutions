class Solution {
public:
    int fact(int i){
        if(i==0 or i==1) return 1;
        return i*fact(i-1);
    }

    string solve(string s, int k){
        sort(s.begin(),s.end());
        if(k<=1) return s;
        //try to reduce k
        int p = fact(s.size()-1);
        int comb_sum = 0;
        //when possible comb_sum exceeds required k, then only we take that item, and reduce prev sum

        for(int i=0;i<s.size();i++){
            if(comb_sum+p>=k){
                swap(s[0],s[i]);
                return s[0]+solve(s.substr(1),k-comb_sum);
            }
            comb_sum+=p;
        }
        return s;
    }

    string getPermutation(int n, int k) {
        string s = "";
        for(int i=1;i<=n;i++){
            s+= to_string(i);
        }
        sort(s.begin(),s.end());
        return solve(s,k);
    }
};
