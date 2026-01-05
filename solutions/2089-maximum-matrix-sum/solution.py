class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        # if odd num are negative, minus the min of abs(matrix[i])
        # if even num are negative, sum of matrix is ans with all pos values
        min_abs = float("inf")
        count_neg = 0
        sumi =0
        for row in matrix:
            for item in row:
                if item < 0:
                    count_neg+=1
                sumi += abs(item)
                min_abs = min(abs(item),min_abs)
        if count_neg%2==0:
            return sumi
        else:
            return sumi-2*min_abs
        
