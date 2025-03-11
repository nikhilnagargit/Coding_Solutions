class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<char,int> m;

        while(right<s.size()){
            m[s[right]]++;
        
            while(left<s.size() and m.size()==3){
                ans+= s.size()-right;
                if(m[s[left]]==1){
                    m.erase(s[left]);
                }
                else{
                    m[s[left]]--;
                }
                left++;
            }

            right++;
        }
        return ans;
    }
};
