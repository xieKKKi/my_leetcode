class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]  # 初始化要给一个[]
        for num in nums:
            result = result + [[num] + i for i in result]
        return result
