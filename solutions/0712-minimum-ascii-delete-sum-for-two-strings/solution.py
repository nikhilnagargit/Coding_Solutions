class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        from functools import lru_cache

        @lru_cache(None)
        def solve(i,j):
            nonlocal s1,s2
            if i==len(s1) and j==len(s2):
                return 0
            b,c,d = [float("inf")]*3
            # delete first string first char
            if i<len(s1):
                b=ord(s1[i])+solve(i+1,j)
            # delete second string first char
            if j<len(s2):
                c=ord(s2[j])+solve(i,j+1)
            # dont' delete if first chars are matching
            if i<len(s1) and j<len(s2) and s1[i]==s2[j]:
                d=solve(i+1,j+1)
            return min(b,c,d)

        return solve(0,0)
        
