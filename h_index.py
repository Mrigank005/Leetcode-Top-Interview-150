"""
274. H-Index

Solution: Sort in descending order
Time Complexity: O(n log n)
Space Complexity: O(1) or O(n) depending on sort implementation
"""

from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        h_index = 0
        for i in range(len(citations)):
            if citations[i] >= i + 1:
                h_index = i + 1
            else:
                break
        return h_index


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    citations1 = [3, 0, 6, 1, 5]
    print(f"Example 1: {solution.hIndex(citations1)}")  # Expected: 3
    
    # Example 2
    citations2 = [1, 3, 1]
    print(f"Example 2: {solution.hIndex(citations2)}")  # Expected: 1
    
    # Edge case: single paper with 0 citations
    citations3 = [0]
    print(f"Example 3: {solution.hIndex(citations3)}")  # Expected: 0
    
    # Edge case: single paper with high citations
    citations4 = [100]
    print(f"Example 4: {solution.hIndex(citations4)}")  # Expected: 1
    
    # Edge case: all zeros
    citations5 = [0, 0, 0]
    print(f"Example 5: {solution.hIndex(citations5)}")  # Expected: 0
    
    # Edge case: all high citations
    citations6 = [10, 10, 10, 10]
    print(f"Example 6: {solution.hIndex(citations6)}")  # Expected: 4
    
    # More complex case
    citations7 = [100, 99, 98, 3, 2, 1]
    print(f"Example 7: {solution.hIndex(citations7)}")  # Expected: 3
