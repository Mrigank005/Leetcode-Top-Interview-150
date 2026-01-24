"""
134. Gas Station

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_tank = 0
        current_tank = 0
        start_station = 0
        for i in range(len(gas)):
            gain = gas[i] - cost[i]
            total_tank += gain
            current_tank += gain
            if current_tank < 0:
                start_station = i + 1
                current_tank = 0
        return start_station if total_tank >= 0 else -1
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    gas1 = [1, 2, 3, 4, 5]
    cost1 = [3, 4, 5, 1, 2]
    print(f"Example 1: {solution.canCompleteCircuit(gas1, cost1)}")  # Expected: 3
    
    # Example 2
    gas2 = [2, 3, 4]
    cost2 = [3, 4, 3]
    print(f"Example 2: {solution.canCompleteCircuit(gas2, cost2)}")  # Expected: -1
    
    # Edge case: single station
    gas3 = [5]
    cost3 = [4]
    print(f"Example 3: {solution.canCompleteCircuit(gas3, cost3)}")  # Expected: 0
    
    # Edge case: single station (impossible)
    gas4 = [2]
    cost4 = [3]
    print(f"Example 4: {solution.canCompleteCircuit(gas4, cost4)}")  # Expected: -1
    
    # Edge case: start from last station
    gas5 = [3, 1, 1]
    cost5 = [1, 2, 2]
    print(f"Example 5: {solution.canCompleteCircuit(gas5, cost5)}")  # Expected: 0
    
    # Edge case: equal gas and cost
    gas6 = [5, 5, 5]
    cost6 = [5, 5, 5]
    print(f"Example 6: {solution.canCompleteCircuit(gas6, cost6)}")  # Expected: 0
    
    # More complex case
    gas7 = [1, 2, 3, 4, 5]
    cost7 = [2, 3, 4, 3, 1]
    print(f"Example 7: {solution.canCompleteCircuit(gas7, cost7)}")  # Expected: 4
