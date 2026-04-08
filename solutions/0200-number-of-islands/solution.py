class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count  = 0
        n = len(grid)
        m = len(grid[0])
        visited = [[0 for _ in range(m)] for _ in range(n)]

        def traverse(i,j):
            if(i>=n or j>=m or i<0 or j<0):
                return
            if(visited[i][j]==1):
                return 
            if(grid[i][j]=="0"):
                return
            visited[i][j]=1
            # go near 4
            traverse(i+1,j)
            traverse(i,j+1)
            traverse(i-1,j)
            traverse(i,j-1)

        for i in range(n):
            for j in range(m):
                if(visited[i][j]==0 and grid[i][j]=="1"):
                    traverse(i,j)
                    count+=1
        return count
        
