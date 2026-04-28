class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        # flatten the grid
        arr = []
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                arr.append(grid[i][j])
        arr.sort()
        median = arr[len(arr)//2]
        req_rem = median%x
        ans = 0
        if(len(arr)==1):
            return ans
        for i in arr:
            if(i%x != req_rem):
                return -1
            ans+= abs(i-median)//x
        return ans
        
