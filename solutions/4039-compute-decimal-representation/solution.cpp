class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        long long multiplier = 1;
        vector<int> ans ;
        while(n){
            int rem = n%10;
            n = n/10;
            if(rem)
            ans.push_back((int)multiplier*rem);
            multiplier*=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
