class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        left = 0
        m = {}
        for right in range(len(s)):
            if(s[right] not in m):
                m[s[right]]=1
            else:
                m[s[right]]+=1
            # check if invalid state
            while(m[s[right]]>1):
                m[s[left]]-=1
                left+=1
            # check the window
            ans = max(right-left+1,ans)
        return ans
            



        
