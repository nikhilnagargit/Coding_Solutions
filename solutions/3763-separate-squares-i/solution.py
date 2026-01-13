class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:

        def calculateAreaUnderLine(p):
            area = 0 
            for i in squares:
                y = i[1]
                s = i[2]
                if p<y:
                    continue
                elif y+s<p:
                    area += s*s
                else:
                    area += (p-y)*s
            return round(area,5)

        bottom = 0
        top = max([ item[2]+item[1] for item in squares])
        halfarea = round(sum([item[2]*item[2] for item in squares])/2,5)
        mid= 0
        while bottom<=top:
            mid = round(bottom + (top-bottom)/2,5)
            underhalfarea = calculateAreaUnderLine(mid)
            if underhalfarea<halfarea:
                bottom = round(mid+0.00001,5)
            else:
                top = round(mid-0.00001,5)
        return top



