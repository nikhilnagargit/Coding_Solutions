class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char>vowels = {'a','e','i','o','u'};
        int ans=0;
      int n = s.size();
        if(n<=1){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            int vcount = 0;
            for(int j=i;j<n;j++){
                if(vowels.find(s[j])!=vowels.end()){
                    vcount++;
                }
                int ccount = j-i-vcount+1;
                if(vcount==ccount and ((vcount*ccount)%k)==0){
                    ans+=1;
                }
                // cout<<vcount<<" "<<ccount<<endl;
            }
        }
        return ans;
    }
};
