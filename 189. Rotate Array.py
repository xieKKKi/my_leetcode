class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        if k == 0:
            return None
        nums[:] = nums[::-1]  # 一定要写成nums[:]，不能写nums，不然list索引会变
        nums[:k] = nums[k-1::-1]
        nums[k:] = nums[:k-1:-1]
        
class Solution2:
    def rotate(self, nums: List[int], k: int) -> None:
        k = k % len(nums)
        nums[:] = nums[-k:] + nums[:-k]   # 一定要写成nums[:]，不能写nums，不然list索引会变
