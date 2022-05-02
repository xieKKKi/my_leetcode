class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        if nums[0] > nums[1]:
            return 0
        if nums[n-1] > nums[n-2]:
            return n-1
        
        def binary_search(start, end):  # 这里保证start和end不为峰值
            mid = int((start + end) / 2)
            if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
                return mid
            elif nums[mid] <= nums[mid-1] and nums[mid] > nums[mid+1]:
                return binary_search(start, mid)
            else:
                return binary_search(mid, end)
        return binary_search(0, n-1)
