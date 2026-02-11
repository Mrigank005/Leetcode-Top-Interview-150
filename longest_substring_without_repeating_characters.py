"""
3. Longest Substring Without Repeating Characters

Time Complexity: O(n)
Space Complexity: O(min(n, m)) where m is charset size
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        left = 0
        max_length = 0
        
        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            
            char_set.add(s[right])
            
            max_length = max(max_length, right - left + 1)
        
        return max_length

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "abcabcbb"
    print(f"Example 1: {solution.lengthOfLongestSubstring(s1)}")  # Expected: 3
    # "abc"
    
    # Example 2
    s2 = "bbbbb"
    print(f"Example 2: {solution.lengthOfLongestSubstring(s2)}")  # Expected: 1
    # "b"
    
    # Example 3
    s3 = "pwwkew"
    print(f"Example 3: {solution.lengthOfLongestSubstring(s3)}")  # Expected: 3
    # "wke"
    
    # Edge case: empty string
    s4 = ""
    print(f"Example 4: {solution.lengthOfLongestSubstring(s4)}")  # Expected: 0
    
    # Edge case: single character
    s5 = "a"
    print(f"Example 5: {solution.lengthOfLongestSubstring(s5)}")  # Expected: 1
    
    # Edge case: all unique characters
    s6 = "abcdef"
    print(f"Example 6: {solution.lengthOfLongestSubstring(s6)}")  # Expected: 6
    
    # Edge case: with spaces and symbols
    s7 = "a b c! @#"
    print(f"Example 7: {solution.lengthOfLongestSubstring(s7)}")  # Expected: 6
    # " b c! @" or "b c! @#"
    
    # Edge case: repeating at start
    s8 = "aab"
    print(f"Example 8: {solution.lengthOfLongestSubstring(s8)}")  # Expected: 2
    # "ab"
    
    # Edge case: repeating at end
    s9 = "abca"
    print(f"Example 9: {solution.lengthOfLongestSubstring(s9)}")  # Expected: 3
    # "abc" or "bca"
    
    # Edge case: long substring in middle
    s11 = "aaabcdefgh"
    print(f"Example 11: {solution.lengthOfLongestSubstring(s11)}")  # Expected: 8
    # "abcdefgh"
    
    # Edge case: with digits
    s12 = "123451234"
    print(f"Example 12: {solution.lengthOfLongestSubstring(s12)}")  # Expected: 5
    # "12345"
