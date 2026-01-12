class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # bfs
        from collections import deque

        dq = deque()
        time = 0
        for i,row in enumerate(grid):
            for j,item in enumerate(row):
                if item==2:
                    dq.append((i,j))

        while dq:
            l = len(dq)
            for i in range(l):
                curr = dq.popleft()
                for d in [(0,1),(0,-1),(-1,0),(1,0)]:
                    newi = curr[0]+d[0]
                    newj = curr[1]+d[1]
                    if(newi>=0 and newi<len(grid) and newj>=0 and newj<len(grid[0]) and grid[newi][newj]==1):
                        grid[newi][newj]=2
                        dq.append((newi,newj))
                
            time+=1

        for i,row in enumerate(grid):
            for j,item in enumerate(row):
                if item==1:
                    return -1
        
        
        return time-1 if time-1>=0 else 0

                
                    

