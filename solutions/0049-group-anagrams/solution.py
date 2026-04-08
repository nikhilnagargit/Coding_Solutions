class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = {}
        for s in strs:
            key = "".join(sorted(s))
            if key in m:
                m[key].append(s)
            else:
                m[key]=[s]
        ans = []
        for k in m:
            ans.append(m[k])
        return ans


        
