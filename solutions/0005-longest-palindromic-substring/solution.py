class Solution:
    def longestPalindrome(self, s: str) -> str:
        dp = [[0]*len(s) for _ in s]
        for i in range(len(s)-1,-1,-1):
            for j in range(0,i+1):
                I = j
                J = len(s)-i-1+j
                if(I==J):
                    dp[I][J]= 1
                elif(I==J-1):
                    dp[I][J]= 1 if s[I]==s[J] else 0
                else:
                    dp[I][J] = 1 if (s[I]==s[J] and dp[I+1][J-1]==1) else 0
        # print(dp)
        maxLen = 0
        maxString = ""
        for i in range(0,len(s)):
            for j in range(0,len(s)):
                if dp[i][j]==1 and maxLen<=j-i:
                    maxLen = j-i
                    maxString = s[i:j+1]
                
        return maxString



            

            
        
