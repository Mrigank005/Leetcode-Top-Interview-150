"""
15. 3Sum

Time Complexity: O(n²)
Space Complexity: O(1) excluding output
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []
        n = len(nums)
        
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            if nums[i] > 0:
                break
            
            left = i + 1
            right = n - 1
            target = -nums[i]
            
            while left < right:
                current_sum = nums[left] + nums[right]
                
                if current_sum == target:
                    result.append([nums[i], nums[left], nums[right]])
                    
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    left += 1
                    right -= 1
                    
                elif current_sum < target:
                    left += 1
                else:
                    right -= 1
        
        return result


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    nums1 = [-1, 0, 1, 2, -1, -4]
    print(f"Example 1: {solution.threeSum(nums1)}")
    # Expected: [[-1, -1, 2], [-1, 0, 1]]
    
    # Example 2
    nums2 = [0, 1, 1]
    print(f"Example 2: {solution.threeSum(nums2)}")
    # Expected: []
    
    # Example 3
    nums3 = [0, 0, 0]
    print(f"Example 3: {solution.threeSum(nums3)}")
    # Expected: [[0, 0, 0]]
    
    # Edge case: exactly 3 elements summing to 0
    nums4 = [-1, 0, 1]
    print(f"Example 4: {solution.threeSum(nums4)}")
    # Expected: [[-1, 0, 1]]
    
    # Edge case: no triplets
    nums5 = [1, 2, 3]
    print(f"Example 5: {solution.threeSum(nums5)}")
    # Expected: []
    
    # Edge case: multiple triplets with duplicates
    nums6 = [-2, 0, 0, 2, 2]
    print(f"Example 6: {solution.threeSum(nums6)}")
    # Expected: [[-2, 0, 2]]
    
    # Edge case: all negative
    nums7 = [-1, -2, -3]
    print(f"Example 7: {solution.threeSum(nums7)}")
    # Expected: []
    
    # Edge case: larger array
    nums8 = [-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6]
    print(f"Example 8: {solution.threeSum(nums8)}")
    # Expected: [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
    
    # Edge case: with zeros
    nums9 = [0, 0, 0, 0]
    print(f"Example 9: {solution.threeSum(nums9)}")
    # Expected: [[0, 0, 0]]
    
    # Edge case: minimum length
    nums10 = [1, -1, 0]
    print(f"Example 10: {solution.threeSum(nums10)}")
    # Expected: [[-1, 0, 1]]
