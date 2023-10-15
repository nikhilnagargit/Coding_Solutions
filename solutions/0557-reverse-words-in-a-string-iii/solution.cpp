class Solution {
public:
    string reverse(string s){
        string a="";
        for(int i=s.length()-1;i>=0;i--){
            a+=s[i];
        }
        return a;
    }
    string reverseWords(string s) {
        string ans="";
        string curr="";
        int i=0;
        while(i<s.length()){
            if(s[i]==' '){
                ans+=reverse(curr)+' ';
                curr="";
            }
            else{
                curr+=s[i];
            }
            i++;
        }
        return ans+reverse(curr);
    }
};
