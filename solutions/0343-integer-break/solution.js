/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {

if (n <= 3) {
            return n - 1;
        }
        
       let dp = Array(n+1).fill(0);

        // Set base cases
        for (let i = 1; i <= 3; i++) {
            dp[i] = i;
        }
        
        for (let num = 4; num <= n; num++) {
            let ans = num;
            for (let i = 2; i < num; i++) {
                ans = Math.max(ans, i * dp[num - i]);
            }
            
            dp[num] = ans;
        }
        
        return dp[n];
}
