"""
14. Longest Common Prefix

Time Complexity: O(S) where S is sum of all characters in all strings
Space Complexity: O(1)
"""

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        for i in range(len(strs[0])):
            char = strs[0][i]
            for j in range(1, len(strs)):
                if i >= len(strs[j]) or strs[j][i] != char:
                    return strs[0][:i]
        return strs[0]

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    strs1 = ["flower", "flow", "flight"]
    print(f"Example 1: '{solution.longestCommonPrefix(strs1)}'")  # Expected: "fl"
    
    # Example 2
    strs2 = ["dog", "racecar", "car"]
    print(f"Example 2: '{solution.longestCommonPrefix(strs2)}'")  # Expected: ""
    
    # Edge case: single string
    strs3 = ["alone"]
    print(f"Example 3: '{solution.longestCommonPrefix(strs3)}'")  # Expected: "alone"
    
    # Edge case: all strings identical
    strs4 = ["test", "test", "test"]
    print(f"Example 4: '{solution.longestCommonPrefix(strs4)}'")  # Expected: "test"
    
    # Edge case: empty string in array
    strs5 = ["", "b"]
    print(f"Example 5: '{solution.longestCommonPrefix(strs5)}'")  # Expected: ""
    
    # Edge case: first string is prefix of all
    strs6 = ["a", "ab", "abc"]
    print(f"Example 6: '{solution.longestCommonPrefix(strs6)}'")  # Expected: "a"
    
    # Edge case: no common prefix from start
    strs7 = ["abc", "bcd", "cde"]
    print(f"Example 7: '{solution.longestCommonPrefix(strs7)}'")  # Expected: ""
    
    # Test horizontal approach
    strs8 = ["flower", "flow", "flight"]
    print(f"Example 8 (horizontal): '{solution.longestCommonPrefixHorizontal(strs8)}'")  # Expected: "fl"
    
    # Test divide and conquer
    strs9 = ["flower", "flow", "flight"]
    print(f"Example 9 (divide & conquer): '{solution.longestCommonPrefixDivideConquer(strs9)}'")  # Expected: "fl"
    
    # Edge case: longer common prefix
    strs10 = ["interspecies", "interstellar", "interstate"]
    print(f"Example 10: '{solution.longestCommonPrefix(strs10)}'")  # Expected: "inters"
