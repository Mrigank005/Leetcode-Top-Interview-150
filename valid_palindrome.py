"""
125. Valid Palindrome

Time Complexity: O(n)
Space Complexity: O(1) for two-pointer approach, O(n) for filter approach
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1
        
        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if s[left].lower() != s[right].lower():
                return False
            
            left += 1
            right -= 1
        
        return True
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "A man, a plan, a canal: Panama"
    print(f"Example 1: {solution.isPalindrome(s1)}")  # Expected: True
    
    # Example 2
    s2 = "race a car"
    print(f"Example 2: {solution.isPalindrome(s2)}")  # Expected: False
    
    # Example 3
    s3 = " "
    print(f"Example 3: {solution.isPalindrome(s3)}")  # Expected: True
    
    # Edge case: empty string
    s4 = ""
    print(f"Example 4: {solution.isPalindrome(s4)}")  # Expected: True
    
    # Edge case: single character
    s5 = "a"
    print(f"Example 5: {solution.isPalindrome(s5)}")  # Expected: True
    
    # Edge case: all special characters
    s6 = ".,!@#"
    print(f"Example 6: {solution.isPalindrome(s6)}")  # Expected: True
    
    # Edge case: with numbers
    s7 = "0P"
    print(f"Example 7: {solution.isPalindrome(s7)}")  # Expected: False
    
    # Edge case: numbers palindrome
    s8 = "1a2b2a1"
    print(f"Example 8: {solution.isPalindrome(s8)}")  # Expected: True
    
