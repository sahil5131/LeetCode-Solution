class Solution:

    def lengthOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        ans=1
        dp = [1 for i in range(n)]
        dp[0]=1
        for i in range(1,n):
            for j in range(i-1, -1, -1):
                if(nums[j]<nums[i]):
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
        