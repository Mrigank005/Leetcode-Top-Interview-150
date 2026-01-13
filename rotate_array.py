"""
189. Rotate Array

Solution 1: Three Reversals (Optimal)
Time Complexity: O(n)
Space Complexity: O(1)

Solution 2: Extra Array 
Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n
        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1) 
        self.reverse(nums, k, n - 1) 
    
    def reverse(self, nums: List[int], start: int, end: int) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
    
    def rotateExtraArray(self, nums: List[int], k: int) -> None:
        """
        Using extra array - O(n) space solution
        """
        n = len(nums)
        k = k % n
        result = [0] * n
        
        # Place each element at its rotated position
        for i in range(n):
            result[(i + k) % n] = nums[i]
        
        # Copy back to nums
        for i in range(n):
            nums[i] = result[i]


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [1, 2, 3, 4, 5, 6, 7]
    solution.rotate(nums1, 3)
    print(f"Example 1: {nums1}")  # Expected: [5, 6, 7, 1, 2, 3, 4]
    
    # Example 2
    nums2 = [-1, -100, 3, 99]
    solution.rotate(nums2, 2)
    print(f"Example 2: {nums2}")  # Expected: [3, 99, -1, -100]
    
    # Edge case: k = 0
    nums3 = [1, 2, 3]
    solution.rotate(nums3, 0)
    print(f"Example 3: {nums3}")  # Expected: [1, 2, 3]
    
    # Edge case: k > n
    nums4 = [1, 2, 3, 4]
    solution.rotate(nums4, 6)  # 6 % 4 = 2
    print(f"Example 4: {nums4}")  # Expected: [3, 4, 1, 2]
    
    # Edge case: k = n (full rotation)
    nums5 = [1, 2, 3]
    solution.rotate(nums5, 3)
    print(f"Example 5: {nums5}")  # Expected: [1, 2, 3]
    
    # Edge case: single element
    nums6 = [1]
    solution.rotate(nums6, 5)
    print(f"Example 6: {nums6}")  # Expected: [1]
