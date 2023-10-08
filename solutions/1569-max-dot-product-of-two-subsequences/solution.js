/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {
    let dp = [];
    let rows = nums2.length;
    let columns = nums1.length;

    // creating two-dimensional array
    for (let i = 0; i < rows; i++) {
        dp[i] = [];
        for (let j = 0; j < columns; j++) {
            dp[i][j] = -99999999;
        }
    }
        // fill for first row
    dp[0][0] = nums1[0]*nums2[0];
    for(let j=1;j<columns;j++){
        dp[0][j] = Math.max(dp[0][j-1],nums2[0]*nums1[j]);
    }
    // fill for first column
        for(let i=1;i<rows;i++){
        dp[i][0] = Math.max(dp[i-1][0],nums2[i]*nums1[0]);
   
    }

    // fill intermediate values
     for(let i=1;i<rows;i++){
         for(let j=1;j<columns;j++){
             dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1],Math.max(dp[i-1][j-1],0)+nums1[j]*nums2[i]);
            
         }
     }
      console.log(dp);
    return dp[rows-1][columns-1];
};
