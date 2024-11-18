class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        for(int i=0;i<code.size();i++){
            if(k>0){
                int sum = 0;
                for(int j=1;j<=k;j++){
                    sum += code[(i+j)%code.size()];
                }
                ans.push_back(sum);
            }
            else if(k<0){
                int sum = 0;
                for(int j=1;j<=abs(k);j++){
                    int idx = i-j;
                    if(idx<0){
                        idx = code.size()+idx;
                    }
                    sum += code[idx];
                }
                ans.push_back(sum);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
