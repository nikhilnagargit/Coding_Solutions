class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # precompute next smaller 
        nextSmallerIndex = [len(heights)]*len(heights)
        prevSmallerIndex = [-1]*len(heights)

        stk = []
        for i in range(0,len(heights)):
            if not stk or heights[stk[-1]]<=heights[i]:
                stk.append(i)
                continue
            # pop until top is lesser
            while stk and heights[stk[-1]]>heights[i]:
                idx=stk.pop()
                # current i is the next smaller for poped indexes
                nextSmallerIndex[idx]=i
            stk.append(i)

        # precompute prevsmaller idex
        stk = []
        for i in range(len(heights)-1,-1,-1):
            if not stk or heights[stk[-1]]<=heights[i]:
                stk.append(i)
                continue
            while stk and heights[stk[-1]]>heights[i]:
                idx = stk.pop()
                prevSmallerIndex[idx]=i
            stk.append(i)
        
        # compute largest rectange

        maxarea = 0
        for i in range(0,len(heights)):
            area = heights[i]*(nextSmallerIndex[i]-prevSmallerIndex[i]-1)
            maxarea = max(maxarea,area)
        return maxarea


        
