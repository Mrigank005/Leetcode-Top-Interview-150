"""
13. Roman to Integer

Time Complexity: O(n)
Space Complexity: O(1)
"""
class Solution:
    def romanToInt(self, s: str) -> int:
        roman_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }        
        result = 0
        n = len(s)        
        for i in range(n):
            if i < n - 1 and roman_map[s[i]] < roman_map[s[i + 1]]:
                result -= roman_map[s[i]]
            else:
                result += roman_map[s[i]]        
        return result
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "III"
    print(f"Example 1: {solution.romanToInt(s1)}")  # Expected: 3
    
    # Example 2
    s2 = "LVIII"
    print(f"Example 2: {solution.romanToInt(s2)}")  # Expected: 58
    
    # Example 3
    s3 = "MCMXCIV"
    print(f"Example 3: {solution.romanToInt(s3)}")  # Expected: 1994
    
    # Edge case: single character
    s4 = "M"
    print(f"Example 4: {solution.romanToInt(s4)}")  # Expected: 1000
    
    # Edge case: IV (subtraction case)
    s5 = "IV"
    print(f"Example 5: {solution.romanToInt(s5)}")  # Expected: 4
    
    # Edge case: IX (subtraction case)
    s6 = "IX"
    print(f"Example 6: {solution.romanToInt(s6)}")  # Expected: 9
    
    # All subtraction cases
    s7 = "CDXLIV"
    print(f"Example 7: {solution.romanToInt(s7)}")  # Expected: 444 (CD=400, XL=40, IV=4)
    
    # Maximum value
    s8 = "MMMCMXCIX"
    print(f"Example 8: {solution.romanToInt(s8)}")  # Expected: 3999
    
    # Simple addition
    s9 = "XXVII"
    print(f"Example 9: {solution.romanToInt(s9)}")  # Expected: 27
    
    # Complex mix
    s10 = "DCXXI"
    print(f"Example 10: {solution.romanToInt(s10)}")  # Expected: 621 (D=500, C=100, XX=20, I=1)
