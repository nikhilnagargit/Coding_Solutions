class Solution {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for(int i=0;i<s.size();i++){
            if('a'<=s[i] and s[i]<='z'){
                filtered+=s[i];
            }
            else if('A'<=s[i] and s[i]<='Z'){
                filtered+=tolower(s[i]);
            }
            else if('0'<=s[i] and s[i]<='9'){
                filtered+=s[i];
            }
        }
 
    string temp = filtered;
    reverse(filtered.begin(),filtered.end());
    return filtered==temp;
    }

};
