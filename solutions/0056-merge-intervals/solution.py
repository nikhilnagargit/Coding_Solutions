class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        ans.append(intervals[0])
        prev = intervals[0]
        for i in range(1,len(intervals)):
            curr = intervals[i]
            prev = ans[-1]
            # compare two
            # second intervals will start after first (gurantee)
            # second interval starts after first ends
            if curr[0] > prev[1]:
                # no need to merge
                ans.append(curr)
            else:
                # second interval ends after frist ends
                ans[-1] = [prev[0],max(curr[1],prev[1])]
        return ans


        
