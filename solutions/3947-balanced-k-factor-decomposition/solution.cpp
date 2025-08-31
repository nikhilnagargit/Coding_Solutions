class Solution {
public:
    vector<vector<int>> ans;
    void defactor(int num,int k,vector<int>& v){
        if(k==0 and num==1){
            ans.push_back(v);
            return;
        }
        if(k==0){
            return;
        }
        for(int i=1;i<=num;i++){
            if(num%i==0){
                v.push_back(i);
                defactor(num/i,k-1,v);
                v.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> v;
        defactor(n,k,v);
        vector<int> mindiffv;
        int mindiff = INT_MAX;
        for(auto v: ans){
            sort(v.begin(),v.end());
            if(v[k-1]-v[0] < mindiff){
                mindiff = v[k-1]-v[0];
                mindiffv = v;
            }
        }
        return mindiffv;
    }
};
