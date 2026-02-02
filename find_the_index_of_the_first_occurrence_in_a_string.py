"""
28. Find the Index of the First Occurrence in a String

Time Complexity: O(n * m)
Space Complexity: O(1)
where n = len(haystack), m = len(needle)
"""


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i:i + m] == needle:
                return i
        return -1
    
    def strStrBuiltIn(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    haystack1 = "sadbutsad"
    needle1 = "sad"
    print(f"Example 1: {solution.strStr(haystack1, needle1)}")  # Expected: 0
    
    # Example 2
    haystack2 = "leetcode"
    needle2 = "leeto"
    print(f"Example 2: {solution.strStr(haystack2, needle2)}")  # Expected: -1
    
    # Edge case: needle at end
    haystack3 = "hello"
    needle3 = "llo"
    print(f"Example 3: {solution.strStr(haystack3, needle3)}")  # Expected: 2
    
    # Edge case: needle is entire haystack
    haystack4 = "test"
    needle4 = "test"
    print(f"Example 4: {solution.strStr(haystack4, needle4)}")  # Expected: 0
    
    # Edge case: single character
    haystack5 = "a"
    needle5 = "a"
    print(f"Example 5: {solution.strStr(haystack5, needle5)}")  # Expected: 0
    
    # Edge case: needle longer than haystack
    haystack6 = "ab"
    needle6 = "abc"
    print(f"Example 6: {solution.strStr(haystack6, needle6)}")  # Expected: -1
    
    # Edge case: multiple occurrences
    haystack7 = "ababcaababcaabc"
    needle7 = "ababcaabc"
    print(f"Example 7: {solution.strStr(haystack7, needle7)}")  # Expected: 6
    
    # Test built-in method
    print(f"Example 8 (built-in): {solution.strStrBuiltIn('sadbutsad', 'sad')}")  # Expected: 0
    
