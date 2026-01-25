"""
42. Trapping Rain Water

Solution 1: Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        left, right = 0, len(height) - 1
        left_max, right_max = 0, 0
        water = 0
        while left < right:
            if height[left] < height[right]:
                if height[left] >= left_max:
                    left_max = height[left]
                else:
                    water += left_max - height[left]
                left += 1
            else:
                if height[right] >= right_max:
                    right_max = height[right]
                else:
                    water += right_max - height[right]
                right -= 1
        return water
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    height1 = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Example 1: {solution.trap(height1)}")  # Expected: 6
    
    # Example 2
    height2 = [4, 2, 0, 3, 2, 5]
    print(f"Example 2: {solution.trap(height2)}")  # Expected: 9
    
    # Edge case: empty
    height3 = []
    print(f"Example 3: {solution.trap(height3)}")  # Expected: 0
    
    # Edge case: single bar
    height4 = [5]
    print(f"Example 4: {solution.trap(height4)}")  # Expected: 0
    
    # Edge case: two bars
    height5 = [3, 1]
    print(f"Example 5: {solution.trap(height5)}")  # Expected: 0
    
    # Edge case: three bars forming valley
    height6 = [3, 0, 2]
    print(f"Example 6: {solution.trap(height6)}")  # Expected: 2
    
    # Edge case: all same height
    height7 = [2, 2, 2, 2]
    print(f"Example 7: {solution.trap(height7)}")  # Expected: 0
    
    # Edge case: increasing
    height8 = [1, 2, 3, 4]
    print(f"Example 8: {solution.trap(height8)}")  # Expected: 0
    
    # Edge case: decreasing
    height9 = [4, 3, 2, 1]
    print(f"Example 9: {solution.trap(height9)}")  # Expected: 0
    
    # Complex case
    height10 = [5, 4, 1, 2, 3, 2, 1, 0, 2]
    print(f"Example 10: {solution.trap(height10)}")  # Expected: 6
    
