"""
27. Remove Element

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0 
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [3, 2, 2, 3]
    val1 = 3
    k1 = solution.removeElement(nums1, val1)
    print(f"Example 1: k = {k1}, nums = {nums1[:k1]}")  # Expected: k = 2, nums = [2, 2]
    
    # Example 2
    nums2 = [0, 1, 2, 2, 3, 0, 4, 2]
    val2 = 2
    k2 = solution.removeElement(nums2, val2)
    print(f"Example 2: k = {k2}, nums = {nums2[:k2]}")  # Expected: k = 5, nums = [0, 1, 3, 0, 4]
    
    # Edge case: empty array
    nums3 = []
    val3 = 0
    k3 = solution.removeElement(nums3, val3)
    print(f"Example 3: k = {k3}, nums = {nums3[:k3]}")  # Expected: k = 0, nums = []
    
    # Edge case: all elements are val
    nums4 = [2, 2, 2, 2]
    val4 = 2
    k4 = solution.removeElement(nums4, val4)
    print(f"Example 4: k = {k4}, nums = {nums4[:k4]}")  # Expected: k = 0, nums = []
    
    # Edge case: no elements are val
    nums5 = [1, 2, 3, 4]
    val5 = 5
    k5 = solution.removeElement(nums5, val5)
    print(f"Example 5: k = {k5}, nums = {nums5[:k5]}")  # Expected: k = 4, nums = [1, 2, 3, 4]
