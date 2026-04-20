class Solution:
    def isValid(self, s: str) -> bool:
        mapper = {")":"(","}":"{","]":"["}
        stk = []
        for c in s:
            if c not in mapper:
                stk.append(c)
            else:
                if stk and stk[-1]==mapper[c]:
                    stk.pop()
                else:
                    return False
        if len(stk)==0:
            return True
        return False



        
        
