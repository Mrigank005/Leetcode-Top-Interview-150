"""
58. Length of Last Word

Time Complexity: O(n)
Space Complexity: O(1)
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        length = 0
        while i >= 0 and s[i] == ' ':
            i -= 1
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
        return length


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "Hello World"
    print(f"Example 1: {solution.lengthOfLastWord(s1)}")  # Expected: 5
    
    # Example 2
    s2 = "   fly me   to   the moon  "
    print(f"Example 2: {solution.lengthOfLastWord(s2)}")  # Expected: 4
    
    # Example 3
    s3 = "luffy is still joyboy"
    print(f"Example 3: {solution.lengthOfLastWord(s3)}")  # Expected: 6
    
    # Edge case: single word
    s4 = "Hello"
    print(f"Example 4: {solution.lengthOfLastWord(s4)}")  # Expected: 5
    
    # Edge case: single word with trailing spaces
    s5 = "a   "
    print(f"Example 5: {solution.lengthOfLastWord(s5)}")  # Expected: 1
    
    # Edge case: single word with leading spaces
    s6 = "   a"
    print(f"Example 6: {solution.lengthOfLastWord(s6)}")  # Expected: 1
    
    # Edge case: multiple spaces between words
    s7 = "a  b    c"
    print(f"Example 7: {solution.lengthOfLastWord(s7)}")  # Expected: 1
    
    # Edge case: long last word
    s8 = "a programming"
    print(f"Example 8: {solution.lengthOfLastWord(s8)}")  # Expected: 11
    
    # Test alternative method
    s9 = "   fly me   to   the moon  "
    print(f"Example 9 (alternative): {solution.lengthOfLastWordAlternative(s9)}")  # Expected: 4
