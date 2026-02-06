"""
167. Two Sum II - Input Array Is Sorted

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            current_sum = numbers[left] + numbers[right]
            
            if current_sum == target:
                return [left + 1, right + 1]
            elif current_sum < target:
                left += 1
            else:
                right -= 1
        
        return []


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    numbers1 = [2, 7, 11, 15]
    target1 = 9
    print(f"Example 1: {solution.twoSum(numbers1, target1)}")  # Expected: [1, 2]
    
    # Example 2
    numbers2 = [2, 3, 4]
    target2 = 6
    print(f"Example 2: {solution.twoSum(numbers2, target2)}")  # Expected: [1, 3]
    
    # Example 3
    numbers3 = [-1, 0]
    target3 = -1
    print(f"Example 3: {solution.twoSum(numbers3, target3)}")  # Expected: [1, 2]
    
    # Edge case: two elements
    numbers4 = [1, 2]
    target4 = 3
    print(f"Example 4: {solution.twoSum(numbers4, target4)}")  # Expected: [1, 2]
    
    # Edge case: negative numbers
    numbers5 = [-5, -3, -1, 0, 2, 4]
    target5 = -4
    print(f"Example 5: {solution.twoSum(numbers5, target5)}")  # Expected: [1, 3] (-5 + 1 = -4)
    
    # Edge case: duplicates
    numbers6 = [1, 2, 3, 3, 4]
    target6 = 6
    print(f"Example 6: {solution.twoSum(numbers6, target6)}")  # Expected: [3, 4] (3 + 3 = 6)
    
    # Edge case: large numbers
    numbers7 = [0, 0, 3, 4]
    target7 = 0
    print(f"Example 7: {solution.twoSum(numbers7, target7)}")  # Expected: [1, 2] (0 + 0 = 0)
    