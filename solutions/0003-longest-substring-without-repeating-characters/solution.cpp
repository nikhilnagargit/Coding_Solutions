class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int left = 0 ;
        int longest = 0;
        for(int right=0;right<s.size();right++){
            m[s[right]]++;

            while(left<=right and m[s[right]]!=1){
                m[s[left]]--;
                left++;
            }
            longest = max(longest,right-left+1);
        }
        return longest;
    }
};
