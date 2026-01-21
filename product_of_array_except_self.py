"""
238. Product of Array Except Self

Time Complexity: O(n)
Space Complexity: O(1) excluding output array
"""

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n
        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]
        suffix = 1
        for i in range(n - 1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]
        return result
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [1, 2, 3, 4]
    print(f"Example 1: {solution.productExceptSelf(nums1)}")  # Expected: [24, 12, 8, 6]
    
    # Example 2
    nums2 = [-1, 1, 0, -3, 3]
    print(f"Example 2: {solution.productExceptSelf(nums2)}")  # Expected: [0, 0, 9, 0, 0]
    
    # Edge case: two elements
    nums3 = [1, 2]
    print(f"Example 3: {solution.productExceptSelf(nums3)}")  # Expected: [2, 1]
    
    # Edge case: with negative numbers
    nums4 = [-1, -2, -3, -4]
    print(f"Example 4: {solution.productExceptSelf(nums4)}")  # Expected: [-24, -12, -8, -6]
    
    # Edge case: multiple zeros
    nums5 = [0, 0, 1]
    print(f"Example 5: {solution.productExceptSelf(nums5)}")  # Expected: [0, 0, 0]
    
    # Edge case: single zero
    nums6 = [1, 0, 3]
    print(f"Example 6: {solution.productExceptSelf(nums6)}")  # Expected: [0, 3, 0]
    
    # Edge case: all ones
    nums7 = [1, 1, 1, 1]
    print(f"Example 7: {solution.productExceptSelf(nums7)}")  # Expected: [1, 1, 1, 1]

