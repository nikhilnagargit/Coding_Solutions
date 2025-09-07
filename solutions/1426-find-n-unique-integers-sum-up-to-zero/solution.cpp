class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
            //even
            for(int i=1;i<=n/2;i++){
                ans.push_back(i);
                ans.push_back(-1*i);
            }

            //if n is odd
            if(n%2!=0){
                ans.push_back(0);
            }
            return ans;
    }
};
