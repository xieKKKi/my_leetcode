class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        
        # 动态规划，dp[i]表示0-i能打劫到的最大值
        dp = [nums[0]] * len(nums)
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]) 
        return dp[-1]
