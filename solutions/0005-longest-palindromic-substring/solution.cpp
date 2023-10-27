class Solution {
public:
    string longestPalindrome(string s) {
        int i=0;
        int l=i;
        int r=i;
        string max_s="";
        string temp_s="";

        while(i<s.size()){
            temp_s += s[i];
            l = i-1;
            r = i+1;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                temp_s = s[l]+temp_s+s[r];
                l--;
                r++;
            }
            if(max_s.size()<temp_s.size()){
                max_s = temp_s;
            }
            i++;
            temp_s = "";
        }

        i=0;
        while(i<s.size()){
            temp_s="";
            l = i;
            r = i+1;
            while(l>=0 and r<s.size() and s[l]==s[r]){
                temp_s = s[l]+temp_s+s[r];
                l--;
                r++;
            }
            if(max_s.size()<temp_s.size()){
                max_s = temp_s;
            }
            i++;
            temp_s = "";
        }
        return max_s;
    }
};
