class Solution {

    bool isPalindrome(string &s, int start, int end ) {

        while( start <= end ) {

            if( s[start] != s[end] )
                return 0;
            
            start++;
            end--;
        }

        return 1;
    }

    string func( string &s, int start, int end ) {

        string ans;

        for( int i = start; i <= end; ++i ) {
            ans+=s[i];
        }

        return ans;
    }

public:
    string longestPalindrome(string s) {
        
        string ans;
        int n = s.size();

        for( int i = 0; i < n; ++i ) {

            for( int j = i; j < n; ++j ) {

                if( j-i+1 > ans.size() && isPalindrome(s, i, j) ) {
                    ans = func(s, i, j );
                }
            }
        }

        return ans;
    }
};
