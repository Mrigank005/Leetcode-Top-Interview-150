"""
88. Merge Sorted Array
"""

from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1  
        j = n - 1  
        k = m + n - 1  
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [1, 2, 3, 0, 0, 0]
    nums2 = [2, 5, 6]
    solution.merge(nums1, 3, nums2, 3)
    print(f"Example 1: {nums1}")  # Expected: [1, 2, 2, 3, 5, 6]
    
    # Example 2
    nums1 = [1]
    nums2 = []
    solution.merge(nums1, 1, nums2, 0)
    print(f"Example 2: {nums1}")  # Expected: [1]
    
    # Example 3
    nums1 = [0]
    nums2 = [1]
    solution.merge(nums1, 0, nums2, 1)
    print(f"Example 3: {nums1}")  # Expected: [1]
