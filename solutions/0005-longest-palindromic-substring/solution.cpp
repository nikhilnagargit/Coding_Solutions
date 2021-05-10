class Solution {
public:
    
    
    int expandFromMiddle(int i,int j,string& s,int n){
//         base cases
        if(i<0 or j>=n){return 0;}
        
        
        while(i>=0 and j<n and s[i]==s[j]){
            i--;
            j++;
        }
        
        return (j-i-1);
    }
    
    
    
    string longestPalindrome(string s) {
        
//       base cases 
        if(s.size()==0)
        {return "";}
        
        if(s.size()==1){return s;}
        
        int len1;
        int len2;
        int max_len;
        int start;
        int end;
        for(int i=0;i<s.size();i++){
            len1 = expandFromMiddle(i,i,s,s.size());
            len2 = expandFromMiddle(i,i+1,s,s.size());
            max_len = max(len1,len2);
            if(max_len>end-start+1){
                 start = i - (max_len-1)/2;
                 end = i + (max_len)/2; 
            }
        }
        
        return s.substr(start,end-start+1);
        
        
    }
};
