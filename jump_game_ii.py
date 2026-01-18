"""
45. Jump Game II

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        
        jumps = 0
        current_end = 0
        farthest = 0
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest
                if current_end >= len(nums) - 1:
                    break        
        return jumps


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [2, 3, 1, 1, 4]
    print(f"Example 1: {solution.jump(nums1)}")  # Expected: 2
    
    # Example 2
    nums2 = [2, 3, 0, 1, 4]
    print(f"Example 2: {solution.jump(nums2)}")  # Expected: 2
    
    # Edge case: single element
    nums3 = [0]
    print(f"Example 3: {solution.jump(nums3)}")  # Expected: 0
    
    # Edge case: two elements
    nums4 = [1, 1]
    print(f"Example 4: {solution.jump(nums4)}")  # Expected: 1
    
    # Edge case: can reach end in one jump
    nums5 = [5, 1, 1, 1, 1]
    print(f"Example 5: {solution.jump(nums5)}")  # Expected: 1
    
    # Multiple jumps needed
    nums6 = [1, 1, 1, 1, 1]
    print(f"Example 6: {solution.jump(nums6)}")  # Expected: 4
    
    # Longer array
    nums7 = [1, 2, 3, 4, 1, 1, 1, 1]
    print(f"Example 7: {solution.jump(nums7)}")  # Expected: 3
    
    # Large jumps available
    nums8 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0]
    print(f"Example 8: {solution.jump(nums8)}")  # Expected: 2
