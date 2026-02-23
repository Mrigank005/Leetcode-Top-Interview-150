"""
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word formed by rearranging the letters of another word, using all 
the original letters exactly once.

Time Complexity: O(n) where n is the length of the strings
Space Complexity: O(k) where k is the number of unique characters (at most 26 for lowercase letters)
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        count_s = {}
        count_t = {}
        
        for char in s:
            count_s[char] = count_s.get(char, 0) + 1
        
        for char in t:
            count_t[char] = count_t.get(char, 0) + 1
        
        return count_s == count_t


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "anagram"
    t1 = "nagaram"
    print(f"Input: s = \"{s1}\", t = \"{t1}\"")
    print(f"Output: {solution.isAnagram(s1, t1)}")  # Expected: True
    print()
    
    # Example 2
    s2 = "rat"
    t2 = "car"
    print(f"Input: s = \"{s2}\", t = \"{t2}\"")
    print(f"Output: {solution.isAnagram(s2, t2)}")  # Expected: False
    print()
    
    # Additional test cases
    s3 = "listen"
    t3 = "silent"
    print(f"Input: s = \"{s3}\", t = \"{t3}\"")
    print(f"Output: {solution.isAnagram(s3, t3)}")  # Expected: True
    print()
    
    s4 = "hello"
    t4 = "world"
    print(f"Input: s = \"{s4}\", t = \"{t4}\"")
    print(f"Output: {solution.isAnagram(s4, t4)}")  # Expected: False
