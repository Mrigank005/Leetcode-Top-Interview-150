"""
26. Remove Duplicates from Sorted Array

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        k = 1 
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return k


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [1, 1, 2]
    k1 = solution.removeDuplicates(nums1)
    print(f"Example 1: k = {k1}, nums = {nums1[:k1]}")  # Expected: k = 2, nums = [1, 2]
    
    # Example 2
    nums2 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    k2 = solution.removeDuplicates(nums2)
    print(f"Example 2: k = {k2}, nums = {nums2[:k2]}")  # Expected: k = 5, nums = [0, 1, 2, 3, 4]
    
    # Edge case: single element
    nums3 = [1]
    k3 = solution.removeDuplicates(nums3)
    print(f"Example 3: k = {k3}, nums = {nums3[:k3]}")  # Expected: k = 1, nums = [1]
    
    # Edge case: all duplicates
    nums4 = [1, 1, 1, 1, 1]
    k4 = solution.removeDuplicates(nums4)
    print(f"Example 4: k = {k4}, nums = {nums4[:k4]}")  # Expected: k = 1, nums = [1]
    
    # Edge case: no duplicates
    nums5 = [1, 2, 3, 4, 5]
    k5 = solution.removeDuplicates(nums5)
    print(f"Example 5: k = {k5}, nums = {nums5[:k5]}")  # Expected: k = 5, nums = [1, 2, 3, 4, 5]
