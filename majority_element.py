"""
169. Majority Element

Solution 1: Boyer-Moore Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)

Solution 2: HashMap
Time Complexity: O(n)
Space Complexity: O(n)
"""

from typing import List
from collections import Counter


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0        
        for num in nums:
            if count == 0:
                candidate = num
                count = 1
            elif num == candidate:
                count += 1
            else:
                count -= 1
        return candidate
    
    def majorityElementHashMap(self, nums: List[int]) -> int:
        freq = {}
        n = len(nums)        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            if freq[num] > n // 2:
                return num
        return -1
    
    def majorityElementCounter(self, nums: List[int]) -> int:
        counts = Counter(nums)
        return counts.most_common(1)[0][0]


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [3, 2, 3]
    print(f"Example 1: {solution.majorityElement(nums1)}")  # Expected: 3
    
    # Example 2
    nums2 = [2, 2, 1, 1, 1, 2, 2]
    print(f"Example 2: {solution.majorityElement(nums2)}")  # Expected: 2
    
    # Edge case: single element
    nums3 = [1]
    print(f"Example 3: {solution.majorityElement(nums3)}")  # Expected: 1
    
    # Edge case: all same elements
    nums4 = [5, 5, 5, 5, 5]
    print(f"Example 4: {solution.majorityElement(nums4)}")  # Expected: 5
    
    # Test with negative numbers
    nums5 = [-1, -1, -1, 2, 2]
    print(f"Example 5: {solution.majorityElement(nums5)}")  # Expected: -1
    
    print("\n--- Testing HashMap approach ---")
    print(f"Example 1 (HashMap): {solution.majorityElementHashMap(nums1)}")
    print(f"Example 2 (HashMap): {solution.majorityElementHashMap(nums2)}")
