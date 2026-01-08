class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [len(nums2)*[0] for _ in range(len(nums1))]
        for i in range(0,len(nums1)):
            for j in range(0,len(nums2)):
                if i==0 and j==0:
                    dp[i][j] = nums1[0]*nums2[0]
                elif i==0:
                    dp[i][j] = max(dp[i][j-1],nums1[i]*nums2[j],)
                elif j==0:
                    dp[i][j] = max(dp[i-1][j],nums1[i]*nums2[j])
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1],nums1[i]*nums2[j]+dp[i-1][j-1],nums1[i]*nums2[j])
        return dp[-1][-1]

