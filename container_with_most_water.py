"""
11. Container With Most Water

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0
        
        while left < right:
            width = right - left
            current_height = min(height[left], height[right])
            current_area = width * current_height
            
            max_area = max(max_area, current_area)
            
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        
        return max_area

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    height1 = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    print(f"Example 1: {solution.maxArea(height1)}")  # Expected: 49
    # Max area between index 1 (height 8) and index 8 (height 7)
    # Area = 7 * min(8, 7) = 7 * 7 = 49
    
    # Example 2
    height2 = [1, 1]
    print(f"Example 2: {solution.maxArea(height2)}")  # Expected: 1
    
    # Edge case: two different heights
    height3 = [1, 2]
    print(f"Example 3: {solution.maxArea(height3)}")  # Expected: 1
    
    # Edge case: increasing heights
    height4 = [1, 2, 3, 4, 5]
    print(f"Example 4: {solution.maxArea(height4)}")  # Expected: 6
    # Between index 0 and 4: width=4, height=min(1,5)=1, area=4
    # Between index 1 and 4: width=3, height=min(2,5)=2, area=6
    
    # Edge case: decreasing heights
    height5 = [5, 4, 3, 2, 1]
    print(f"Example 5: {solution.maxArea(height5)}")  # Expected: 6
    
    # Edge case: all same height
    height6 = [3, 3, 3, 3]
    print(f"Example 6: {solution.maxArea(height6)}")  # Expected: 9
    # Between index 0 and 3: width=3, height=3, area=9
    
    # Edge case: tall on edges
    height7 = [9, 1, 1, 1, 9]
    print(f"Example 7: {solution.maxArea(height7)}")  # Expected: 36
    # Between index 0 and 4: width=4, height=min(9,9)=9, area=36
  