"""
209. Minimum Size Subarray Sum

Time Complexity: O(n)
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        min_length = float('inf')
        window_sum = 0
        left = 0
        
        for right in range(n):
            window_sum += nums[right]
            while window_sum >= target:
                min_length = min(min_length, right - left + 1)
                window_sum -= nums[left]
                left += 1
        
        return min_length if min_length != float('inf') else 0


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    target1 = 7
    nums1 = [2, 3, 1, 2, 4, 3]
    print(f"Example 1: {solution.minSubArrayLen(target1, nums1)}")  # Expected: 2
    # Subarray [4, 3] has sum 7
    
    # Example 2
    target2 = 4
    nums2 = [1, 4, 4]
    print(f"Example 2: {solution.minSubArrayLen(target2, nums2)}")  # Expected: 1
    # Single element [4] has sum 4
    
    # Example 3
    target3 = 11
    nums3 = [1, 1, 1, 1, 1, 1, 1, 1]
    print(f"Example 3: {solution.minSubArrayLen(target3, nums3)}")  # Expected: 0
    # Maximum sum is 8, cannot reach 11
    
    # Edge case: single element matching
    target4 = 5
    nums4 = [5]
    print(f"Example 4: {solution.minSubArrayLen(target4, nums4)}")  # Expected: 1
    
    # Edge case: entire array needed
    target5 = 15
    nums5 = [1, 2, 3, 4, 5]
    print(f"Example 5: {solution.minSubArrayLen(target5, nums5)}")  # Expected: 5
    # Sum = 15
    
    # Edge case: first element is sufficient
    target6 = 3
    nums6 = [5, 1, 1, 1]
    print(f"Example 6: {solution.minSubArrayLen(target6, nums6)}")  # Expected: 1
    
    # Edge case: target = 1 (minimum)
    target7 = 1
    nums7 = [1, 2, 3]
    print(f"Example 7: {solution.minSubArrayLen(target7, nums7)}")  # Expected: 1
    
    # Edge case: large target, cannot achieve
    target8 = 100
    nums8 = [1, 2, 3, 4, 5]
    print(f"Example 8: {solution.minSubArrayLen(target8, nums8)}")  # Expected: 0
    
    # Edge case: consecutive elements
    target9 = 15
    nums9 = [1, 2, 3, 4, 5, 6, 7, 8]
    print(f"Example 9: {solution.minSubArrayLen(target9, nums9)}")  # Expected: 5
    # [1,2,3,4,5] = 15 or [2,3,4,6] = 15 (but need to check which is shorter)
