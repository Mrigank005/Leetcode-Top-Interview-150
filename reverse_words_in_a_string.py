"""
151. Reverse Words in a String

Time Complexity: O(n)
Space Complexity: O(n) for the result
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        return ' '.join(reversed(words))

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "the sky is blue"
    print(f"Example 1: '{solution.reverseWords(s1)}'")  # Expected: "blue is sky the"
    
    # Example 2
    s2 = "  hello world  "
    print(f"Example 2: '{solution.reverseWords(s2)}'")  # Expected: "world hello"
    
    # Example 3
    s3 = "a good   example"
    print(f"Example 3: '{solution.reverseWords(s3)}'")  # Expected: "example good a"
    
    # Edge case: single word
    s4 = "hello"
    print(f"Example 4: '{solution.reverseWords(s4)}'")  # Expected: "hello"
    
    # Edge case: two words
    s5 = "hello world"
    print(f"Example 5: '{solution.reverseWords(s5)}'")  # Expected: "world hello"
    
    # Edge case: lots of spaces
    s6 = "   a   b   c   "
    print(f"Example 6: '{solution.reverseWords(s6)}'")  # Expected: "c b a"
    
    # Test manual approach
    s7 = "the sky is blue"
    print(f"Example 7 (manual): '{solution.reverseWordsManual(s7)}'")  # Expected: "blue is sky the"
    
    # Test two-reversal approach
    s8 = "a good   example"
    print(f"Example 8 (two-reversal): '{solution.reverseWordsTwoReversals(s8)}'")  # Expected: "example good a"
