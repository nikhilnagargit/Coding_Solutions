class Solution {
public:
    long long minimumSteps(string s) {
        long long ans =0 ;
        int i=s.size()-1;
        long long countof1 = 0;
        while(i>=0){
            cout<<s[i]<<" ";
            if(s[i]=='1'){
                // cout<<s.size()-i-1<<"-"<<countof1<<"   ";
                ans+= (s.size()-i-1)-countof1;
                countof1++;
            }
            i--;
        }
        return ans;
    }
};
