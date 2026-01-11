class Solution:
    def maxAreaInHistogram(self,arr):
        stk = [-1]
        maxarea = 0
        for i in range(0,len(arr)):
            while(len(stk)>1 and arr[stk[-1]]>=arr[i]):
                right = i
                t = stk.pop()
                left = stk[-1]
                maxarea = max(maxarea,(right-left-1)*arr[t])
            stk.append(i)
        while(len(stk)>1):
            right = len(arr)
            t = stk.pop()
            left = stk[-1]
            maxarea = max(maxarea,(right-left-1)*arr[t])
        return maxarea
            
            

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # convert in maximum reactangle area in a historgram,
        # row by row make a new histogram, if there is 0, that column will become 0 for that histogram
        arr = [0]*len(matrix[0])
        maxarea = 0
        for i in range(len(matrix)):
            newarr = arr.copy()
            for j in range(len(matrix[0])):
                if matrix[i][j]=="0":
                    newarr[j]=0
                else:
                    newarr[j]=arr[j]+1
            maxarea = max(maxarea,self.maxAreaInHistogram(newarr))
            arr = newarr
        return maxarea

                    
