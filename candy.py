"""
135. Candy

Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n 
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)        
        return sum(candies)


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    ratings1 = [1, 0, 2]
    print(f"Example 1: {solution.candy(ratings1)}")  # Expected: 5 (candies: [2,1,2])
    
    # Example 2
    ratings2 = [1, 2, 2]
    print(f"Example 2: {solution.candy(ratings2)}")  # Expected: 4 (candies: [1,2,1])
    
    # Edge case: single child
    ratings3 = [1]
    print(f"Example 3: {solution.candy(ratings3)}")  # Expected: 1
    
    # Edge case: all increasing
    ratings4 = [1, 2, 3, 4, 5]
    print(f"Example 4: {solution.candy(ratings4)}")  # Expected: 15 (candies: [1,2,3,4,5])
    
    # Edge case: all decreasing
    ratings5 = [5, 4, 3, 2, 1]
    print(f"Example 5: {solution.candy(ratings5)}")  # Expected: 15 (candies: [5,4,3,2,1])
    
    # Edge case: all same
    ratings6 = [1, 1, 1, 1]
    print(f"Example 6: {solution.candy(ratings6)}")  # Expected: 4 (candies: [1,1,1,1])
    
    # Complex case: valley in middle
    ratings7 = [1, 2, 3, 2, 1]
    print(f"Example 7: {solution.candy(ratings7)}")  # Expected: 9 (candies: [1,2,3,2,1])
    
    # Complex case: peak in middle
    ratings8 = [1, 3, 2, 2, 1]
    print(f"Example 8: {solution.candy(ratings8)}")  # Expected: 7 (candies: [1,3,1,2,1])
    
    # Complex case from LeetCode
    ratings9 = [1, 2, 87, 87, 87, 2, 1]
    print(f"Example 9: {solution.candy(ratings9)}")  # Expected: 13
