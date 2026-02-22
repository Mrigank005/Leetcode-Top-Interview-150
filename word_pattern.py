"""
290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in 
pattern and a non-empty word in s.

Time Complexity: O(n + m) where n is the length of pattern and m is the length of s
Space Complexity: O(w) where w is the number of unique words
"""

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        
        pattern_to_word = {}
        word_to_pattern = {}
        
        for char, word in zip(pattern, words):
            if char in pattern_to_word:
                if pattern_to_word[char] != word:
                    return False
            else:
                pattern_to_word[char] = word
            
            if word in word_to_pattern:
                if word_to_pattern[word] != char:
                    return False
            else:
                word_to_pattern[word] = char
        
        return True


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    pattern1 = "abba"
    s1 = "dog cat cat dog"
    print(f"Input: pattern = \"{pattern1}\", s = \"{s1}\"")
    print(f"Output: {solution.wordPattern(pattern1, s1)}")  # Expected: True
    print()
    
    # Example 2
    pattern2 = "abba"
    s2 = "dog cat cat fish"
    print(f"Input: pattern = \"{pattern2}\", s = \"{s2}\"")
    print(f"Output: {solution.wordPattern(pattern2, s2)}")  # Expected: False
    print()
    
    # Example 3
    pattern3 = "aaaa"
    s3 = "dog cat cat dog"
    print(f"Input: pattern = \"{pattern3}\", s = \"{s3}\"")
    print(f"Output: {solution.wordPattern(pattern3, s3)}")  # Expected: False
    print()
    
    # Additional test case
    pattern4 = "abba"
    s4 = "dog dog dog dog"
    print(f"Input: pattern = \"{pattern4}\", s = \"{s4}\"")
    print(f"Output: {solution.wordPattern(pattern4, s4)}")  # Expected: False
