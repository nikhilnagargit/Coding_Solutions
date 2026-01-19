class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        prefixSumMatrix = [[0]*len(mat[0]) for _ in mat]
        for i in range(0,len(mat)):
            for j in range(0,len(mat[0])):
                if j==0:
                    prefixSumMatrix[i][j]=mat[i][j]
                else:
                    prefixSumMatrix[i][j] = mat[i][j]+prefixSumMatrix[i][j-1]
        
        def checkSquarePossibleWithThreshold(side):
            for i in range(side-1,len(mat)):
                for j in range(side-1,len(mat[0])):
                    sumi = 0
                    for s in range(0,side):
                        # for this many rows , calculate the sum
                        if j-side>=0:
                            sumi+= prefixSumMatrix[i-s][j] - prefixSumMatrix[i-s][j-side]
                        else:
                            sumi+= prefixSumMatrix[i-s][j]
                    if sumi<=threshold:
                        return True
            return False
                        
                  
                        
        left = 1
        right = max(len(mat),len(mat[0]))
        while(left<=right):
            mid = left + (right-left)//2
            if checkSquarePossibleWithThreshold(mid):
                left = mid+1
            else:
                right = mid-1
        
        if(checkSquarePossibleWithThreshold(left-1)):
            return left-1
        
        return -1
        
