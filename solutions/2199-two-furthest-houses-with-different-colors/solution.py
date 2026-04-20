class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        first = colors[0]
        last = colors[-1]
        ans = 0
        for i in range(len(colors)):
            if(first!=colors[i]):
                ans = max(ans,abs(0-i))
            if(last!=colors[i]):
                ans = max(ans,abs(len(colors)-i-1))
        return ans


        
