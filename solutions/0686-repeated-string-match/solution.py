class Solution:
    
    def checkKMP(self,s,p):
        def prepareLPS():
            lps = [0]*len(p)
            length = 0
            i=1
            while(i<len(p)):
                if p[length]==p[i]:
                    length+=1
                    lps[i]=length
                    i+=1
                elif p[length]!=p[i] and length!=0:
                    length = lps[length-1]
                else:
                    length=0
                    i+=1
            return lps

        lps = prepareLPS()

        # start string matching
        i=0
        j=0

        while(i<=len(s)):
            if j==len(p):
                return True
            elif i==len(s):
                return False
            elif(s[i]==p[j]):
                i+=1
                j+=1
            elif j!=0:
                j = lps[j-1]
            else:
                i+=1

        return False



    def repeatedStringMatch(self, a: str, b: str) -> int:
        maxtimes = int((len(b)/len(a)))
        s = b
        for m in range(maxtimes,maxtimes+3):
            p = a*m
            if(self.checkKMP(p,s)):
                return m
        return -1


        
