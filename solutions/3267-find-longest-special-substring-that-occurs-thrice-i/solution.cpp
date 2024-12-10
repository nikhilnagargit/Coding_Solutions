class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        for(int k=0;k<s.size();k++){
        for(int l=1;l<s.size();l++){
            string prefix = s.substr(k,l);
            int flag = 0;
            for(auto& a:prefix){
                if(a!=prefix[0]){
                    flag = 1;
                    break;
                }
            }
            if(flag)continue;
            
            // cout<<prefix<<",";
            int count = 1;
            for(int i=1+k;i<=s.size();i++){
                if(s.substr(i,l)==prefix) count++;
            }
            // cout<<count<<endl;
            if(count>=3){
                ans = max(ans,l);
            }
        
        }
        }
        return ans;
    }
};
