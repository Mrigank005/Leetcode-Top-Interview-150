"""
121. Best Time to Buy and Sell Stock

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0        
        min_price = float('inf')
        max_profit = 0        
        for price in prices:
            min_price = min(min_price, price)
            profit = price - min_price
            max_profit = max(max_profit, profit)        
        return max_profit

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    prices1 = [7, 1, 5, 3, 6, 4]
    print(f"Example 1: {solution.maxProfit(prices1)}")  # Expected: 5
    
    # Example 2
    prices2 = [7, 6, 4, 3, 1]
    print(f"Example 2: {solution.maxProfit(prices2)}")  # Expected: 0
    
    # Edge case: single price
    prices3 = [5]
    print(f"Example 3: {solution.maxProfit(prices3)}")  # Expected: 0
    
    # Edge case: two prices increasing
    prices4 = [1, 2]
    print(f"Example 4: {solution.maxProfit(prices4)}")  # Expected: 1
    
    # Edge case: two prices decreasing
    prices5 = [2, 1]
    print(f"Example 5: {solution.maxProfit(prices5)}")  # Expected: 0
    
    # Counter-example from explanation
    prices6 = [2, 4, 1]
    print(f"Example 6: {solution.maxProfit(prices6)}")  # Expected: 2
    
    # Large profit at end
    prices7 = [3, 2, 6, 5, 0, 3]
    print(f"Example 7: {solution.maxProfit(prices7)}")  # Expected: 4 (2->6)
