class Solution:
    def getDistances(self, nums: List[int]) -> List[int]:
        m = {}
        for i,value in enumerate(nums):
            if value in m:
                m[value].append(i)
            else:
                m[value] = [i]

        ans = [0 for _ in range(len(nums))]
        # loop on each key value pair of that dict.
        for k,l in m.items():
            if len(l)>1:
                # process l and get each value and put in ans
                arr = l
                leftsum = 0
                totalsum = sum(l)
                for i in range(len(l)):
                    leftsum = leftsum +( l[i-1] if i>0 else 0)
                    rightsum = totalsum - leftsum - l[i]
                    leftvalue = abs(leftsum - (i)*l[i])
                    rightvalue = abs(rightsum - (len(l)-i-1)*l[i] )
                    ans[l[i]]=rightvalue+leftvalue
        return ans
        
