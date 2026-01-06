class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk = []
        next_greater = {}
        for n in reversed(nums2):
            while stk and stk[-1]<n:
                stk.pop()
            next_greater[n] = stk[-1] if stk else -1
            stk.append(n)
        return [next_greater[i] for i in nums1]


            

