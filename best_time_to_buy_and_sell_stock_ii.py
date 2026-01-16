"""
122. Best Time to Buy and Sell Stock II

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                max_profit += prices[i] - prices[i - 1]
        return max_profit
    


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Example 1: {solution.maxProfit(prices1)}")  # Expected: 7
    
    # Example 2
    prices2 = [1, 2, 3, 4, 5]
    print(f"Example 2: {solution.maxProfit(prices2)}")  # Expected: 4
    
    # Example 3
    prices3 = [7, 6, 4, 3, 1]
    print(f"Example 3: {solution.maxProfit(prices3)}")  # Expected: 0
    
    # Edge case: single price
    prices4 = [5]
    print(f"Example 4: {solution.maxProfit(prices4)}")  # Expected: 0
    
    # Edge case: two prices increasing
    prices5 = [1, 5]
    print(f"Example 5: {solution.maxProfit(prices5)}")  # Expected: 4
    
    # Edge case: alternating prices
    prices6 = [1, 3, 2, 4, 1, 5]
    print(f"Example 6: {solution.maxProfit(prices6)}")  # Expected: 2+2+4 = 8
    
    # All same prices
    prices7 = [5, 5, 5, 5]
    print(f"Example 7: {solution.maxProfit(prices7)}")  # Expected: 0
