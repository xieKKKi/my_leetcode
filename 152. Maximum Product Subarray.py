class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxP, minP, ans = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            _max, _min = maxP, minP
            maxP = max(_max * nums[i], _min * nums[i], nums[i])
            minP = min(_max * nums[i], _min * nums[i], nums[i])
            ans = max(maxP, ans)
        return ans
