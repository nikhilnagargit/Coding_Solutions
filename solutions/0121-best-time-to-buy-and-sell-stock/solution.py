class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minima = prices[0]
        maxprofit = 0
        for i in range(1,len(prices)):
            maxprofit = max(maxprofit, prices[i]-minima)
            minima = min(minima,prices[i])
        return maxprofit

