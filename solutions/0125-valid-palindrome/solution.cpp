class Solution {
public:
    bool isPalindrome(string s) {
        //filter and reform. or just ignore 
        int left = 0;
        int right = s.size();
        while(left<right){
            char c1 = tolower(s[left]);
            char c2 = tolower(s[right]);
            if(((c1>='a' and c1<='z') or (c1>='0' and c1<='9')) and ((c2>='a' and c2<='z' )or(c2>='0' and c2<='9'))){
                if(c1!=c2) return false;
                left++;
                right--;
            }
            else if((c1>='a' and c1<='z') or (c1>='0' and c1<='9')){
                right--;
            }
            else{
                left++;
            }
        }
        return true;
    }
};
