class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        from collections import deque
        dq = deque()
        ans = []
        def insertInDq(item,i):
            if not dq:
                dq.append((item,i))
                return
            while dq and dq[-1][0]<=item:
                dq.pop()
            dq.append((item,i))

        for i in range(0,len(nums)):
            insertInDq(nums[i],i)
            # for taking max, make sure it is valid in range
            if i>=k-1:
                while dq and dq[0][1]<i-k+1:
                    dq.popleft()
                ans.append(dq[0][0])
        return ans





        
