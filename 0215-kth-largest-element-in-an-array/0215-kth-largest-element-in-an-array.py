import random

class Solution(object):
    def findKthLargest(self, nums, k):
        left = 0
        right = len(nums) - 1
        target = len(nums) - k  # kth largest = (n-k)th smallest

        while True:
            # בוחרים pivot אקראי
            pivot_index = random.randint(left, right)
            pivot = nums[pivot_index]
            nums[pivot_index], nums[right] = nums[right], nums[pivot_index]

            # Dutch National Flag partition (שלושה חלקים)
            start = left
            end = right
            i = left

            while i <= end:
                if nums[i] < pivot:
                    nums[start], nums[i] = nums[i], nums[start]
                    start += 1
                    i += 1
                elif nums[i] > pivot:
                    nums[i], nums[end] = nums[end], nums[i]
                    end -= 1
                else:
                    i += 1

            # עכשיו:
            # nums[left:start] < pivot
            # nums[start:end+1] == pivot
            # nums[end+1:right+1] > pivot

            if target < start:
                right = start - 1
            elif target > end:
                left = end + 1
            else:
                return pivot
