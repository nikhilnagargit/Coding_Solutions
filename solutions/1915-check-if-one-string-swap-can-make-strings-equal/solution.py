class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        mismatch_indices = []
        for i in range(0,len(s1)):
            if(s1[i]!=s2[i]):
                mismatch_indices.append(i)
        if(len(mismatch_indices)==1 or len(mismatch_indices)>2):
            return False
        if(len(mismatch_indices)==0):
            return True
        i = mismatch_indices[0]
        j = mismatch_indices[1]
        if(s1[i]==s2[j] and s1[j]==s2[i]):
            return True
        return False

        
