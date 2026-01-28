"""
12. Integer to Roman

Time Complexity: O(1) - at most 13 symbols, each used at most 3-4 times
Space Complexity: O(1) - constant space for mapping
"""


class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        result = []        
        for i in range(len(values)):
            count = num // values[i]
            if count:
                result.append(symbols[i] * count)
                num -= values[i] * count        
        return ''.join(result)


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    num1 = 3749
    print(f"Example 1: {solution.intToRoman(num1)}")  # Expected: "MMMDCCXLIX"
    
    # Example 2
    num2 = 58
    print(f"Example 2: {solution.intToRoman(num2)}")  # Expected: "LVIII"
    
    # Example 3
    num3 = 1994
    print(f"Example 3: {solution.intToRoman(num3)}")  # Expected: "MCMXCIV"
    
    # Edge case: minimum value
    num4 = 1
    print(f"Example 4: {solution.intToRoman(num4)}")  # Expected: "I"
    
    # Edge case: maximum value
    num5 = 3999
    print(f"Example 5: {solution.intToRoman(num5)}")  # Expected: "MMMCMXCIX"
    
    # All subtractive forms
    num6 = 444
    print(f"Example 6: {solution.intToRoman(num6)}")  # Expected: "CDXLIV"
    
    # Simple values
    num7 = 27
    print(f"Example 7: {solution.intToRoman(num7)}")  # Expected: "XXVII"
    
    # Only subtractive forms
    num8 = 49
    print(f"Example 8: {solution.intToRoman(num8)}")  # Expected: "XLIX"
    
    # Test with alternative method
    num9 = 1994
    print(f"Example 9 (alternative): {solution.intToRomanAlternative(num9)}")  # Expected: "MCMXCIV"
    
    # Edge case: round thousands
    num10 = 3000
    print(f"Example 10: {solution.intToRoman(num10)}")  # Expected: "MMM"
