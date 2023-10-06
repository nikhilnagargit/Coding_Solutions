class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int j = 0;
        int k = 0;
        if(haystack.size()<needle.size()){
            return -1;
        }
        while(k<haystack.size()-needle.size()+1){
            j = 0;
            i = k;
            while(j<needle.size() && i<haystack.size()){
                if(haystack[i]==needle[j]){
                    j++;
                    i++;
                }
                else{
                    break;
                }
            }
            if(j==needle.size()){
                return k;
            }
            k++;
        }
        return -1;
    }
};
