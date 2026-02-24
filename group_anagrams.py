"""
49. Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

Time Complexity: O(n * k * log(k)) where n is the number of strings and k is the maximum length of a string
Space Complexity: O(n * k) for storing all strings in the hash map
"""

from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = defaultdict(list)
        
        for s in strs:
            sorted_str = ''.join(sorted(s))
            anagram_groups[sorted_str].append(s)
        
        return list(anagram_groups.values())


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test case 1
    strs1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(f"Input: {strs1}")
    print(f"Output: {solution.groupAnagrams(strs1)}")
    print()
    
    # Test case 2
    strs2 = [""]
    print(f"Input: {strs2}")
    print(f"Output: {solution.groupAnagrams(strs2)}")
    print()
    
    # Test case 3
    strs3 = ["a"]
    print(f"Input: {strs3}")
    print(f"Output: {solution.groupAnagrams(strs3)}")
    print()
