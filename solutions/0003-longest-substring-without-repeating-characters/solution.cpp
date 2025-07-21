class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        int left = 0;
        unordered_set<char> se;
        int max_len = 1;
        for(int right=0;right<s.size();right++){
            while(se.count(s[right])){
                se.erase(s[left]);
                left++;
            }
            se.insert(s[right]);
            max_len= max(max_len,right-left+1);
        }
        return max_len;
    }
};
