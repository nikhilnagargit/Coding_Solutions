class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # accumulate numbers in stack , and pop if next greater is found
        stk = []
        nextgreater = {}
        for val in (nums2):
            while len(stk)!=0 and stk[-1]<val:
                item = stk[-1]
                stk.pop()
                nextgreater[item] = val
            stk.append(val)

        ans = []
        for i in nums1:
            if i in nextgreater:
                ans.append(nextgreater[i])
            else:
                ans.append(-1)
        return ans

# nums2 = 1,3,4,2
#ng = {}

        



            

