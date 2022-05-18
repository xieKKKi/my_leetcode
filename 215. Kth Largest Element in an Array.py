class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        def quickSort(left, right):
            pivot = nums[left]
            i, j = left, right
            while i < j:
                while i < j and nums[j] <= pivot:
                    j -= 1
                nums[i] = nums[j]

                while i < j and nums[i] >= pivot:
                    i += 1
                nums[j] = nums[i]

            nums[i] = pivot

            if i == k-1:  # 这里是k-1
                return nums[i]
            elif i < k-1:
                return quickSort(i+1, right)
            else:
                return quickSort(left, i-1)
        return quickSort(0, len(nums) - 1)
