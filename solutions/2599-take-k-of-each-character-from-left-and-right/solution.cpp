class Solution {
public:
    int takeCharacters(string s, int k) {
        int acount=0, bcount=0, ccount = 0;
        for(auto c:s){
            if(c=='a') acount++;
            else if(c=='b')bcount++;
            else if(c=='c')ccount++;
        }
        // cout<<acount<<","<<bcount<<","<<ccount<<endl;
        if(acount<k or bcount<k or ccount<k) return -1;
        if(k==0) return 0;

        int a_limit = acount - k;
        int b_limit = bcount - k;
        int c_limit = ccount - k;

        int a = 0;
        int b = 0;
        int c = 0;
        int max_removable = 0;

        int left = 0;
        int right = 0;

        while(right<=s.size() and left<=s.size()){
            if(a<=a_limit and b<=b_limit and c<=c_limit){
                    if(s[right]=='a') a++;
                    else if(s[right]=='b')b++;
                    else c++;
                max_removable = max(max_removable, right - left  );
                right++;
            }
            else{
                if(s[left]=='a') a--;
                else if(s[left]=='b')b--;
                else c--;
                left++;
            }
        }
        // cout<<max_removable;

        return s.size()-max_removable;
        
    }
};
