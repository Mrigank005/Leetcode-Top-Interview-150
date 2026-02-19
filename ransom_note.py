"""
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed 
by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Time Complexity: O(m + n) where m = len(ransomNote), n = len(magazine)
Space Complexity: O(1) - at most 26 lowercase letters
"""

from typing import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_count = Counter(magazine)
        
        for char in ransomNote:
            if magazine_count[char] <= 0:
                return False
            magazine_count[char] -= 1
        
        return True

# Test cases
def test_ransom_note():
    solution = Solution()
    
    # Test case 1: Example 1
    assert solution.canConstruct("a", "b") == False
    print("Test 1 passed: Different characters")
    
    # Test case 2: Example 2
    assert solution.canConstruct("aa", "ab") == False
    print("Test 2 passed: Not enough characters")
    
    # Test case 3: Example 3
    assert solution.canConstruct("aa", "aab") == True
    print("Test 3 passed: Enough characters")
    
    # Test case 4: Empty ransom note
    assert solution.canConstruct("", "abc") == True
    print("Test 4 passed: Empty ransom note")
    
    # Test case 5: Single character match
    assert solution.canConstruct("a", "a") == True
    print("Test 5 passed: Single character match")
    
    # Test case 6: Ransom note longer than magazine
    assert solution.canConstruct("abcd", "abc") == False
    print("Test 6 passed: Ransom note longer")
    
    # Test case 7: All characters used
    assert solution.canConstruct("abc", "abc") == True
    print("Test 7 passed: All characters used")
    
    # Test case 8: Multiple of same character
    assert solution.canConstruct("aaa", "aaaa") == True
    print("Test 8 passed: Multiple same character")
    
    # Test case 9: Mixed characters
    assert solution.canConstruct("abc", "aabbcc") == True
    print("Test 9 passed: Mixed characters")
    
    # Test case 10: Complex case
    assert solution.canConstruct("hello", "hlleox") == True
    print("Test 10 passed: Complex case - all characters available")
    
    # Test case 11: Complex case success
    assert solution.canConstruct("hello", "helloworld") == True
    print("Test 11 passed: Complex case - success")
    
    # Test case 12: Repeated letters
    assert solution.canConstruct("aabbcc", "aabbccd") == True
    print("Test 12 passed: Repeated letters")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_ransom_note()
