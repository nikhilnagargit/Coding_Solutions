class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.size()>str1.size()){
            return false;
        }
        int idx1 = 0;
        int idx2 = 0;

        while(idx1<str1.size() and idx2<str2.size()){
            if(str1[idx1]==str2[idx2] or ((str1[idx1]+1)-'a')%26 == str2[idx2]-'a'){
                idx1++;
                idx2++;
            }
            else{
                idx1++;
            }
        }
        if(idx2>=str2.size()){
            return true;
        }
        return false;
    }
};
