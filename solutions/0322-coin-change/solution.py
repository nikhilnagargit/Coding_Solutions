class Solution(object):
    def coinChange(self, coins, amount):
        dp = [99999]*(amount+1)
        dp[0] = 0
        for i in range(0,len(coins)):
            for j in range(coins[i],amount+1):
                dp[j] = min(dp[j],1+dp[j-coins[i]])
        if(dp[amount]>amount):
            return -1
        return dp[amount]
                
                    
        
        
