"""
55. Jump Game

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reach = 0
        for i in range(len(nums)):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + nums[i])
            if max_reach >= len(nums) - 1:
                return True
        return True
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [2, 3, 1, 1, 4]
    print(f"Example 1: {solution.canJump(nums1)}")  # Expected: True
    
    # Example 2
    nums2 = [3, 2, 1, 0, 4]
    print(f"Example 2: {solution.canJump(nums2)}")  # Expected: False
    
    # Edge case: single element
    nums3 = [0]
    print(f"Example 3: {solution.canJump(nums3)}")  # Expected: True
    
    # Edge case: can't move from start
    nums4 = [0, 1]
    print(f"Example 4: {solution.canJump(nums4)}")  # Expected: False
    
    # Edge case: large jump at start
    nums5 = [5, 1, 1, 1, 1]
    print(f"Example 5: {solution.canJump(nums5)}")  # Expected: True
    
    # Edge case: zeros in middle but reachable
    nums6 = [2, 0, 0]
    print(f"Example 6: {solution.canJump(nums6)}")  # Expected: True
    
    # Edge case: multiple paths
    nums7 = [2, 5, 0, 0]
    print(f"Example 7: {solution.canJump(nums7)}")  # Expected: True
    
