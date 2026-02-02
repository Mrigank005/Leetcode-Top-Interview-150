"""
6. Zigzag Conversion

Time Complexity: O(n) where n is length of string
Space Complexity: O(n) for storing rows
"""


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        rows = [''] * numRows
        current_row = 0
        going_down = False
        for char in s:
            rows[current_row] += char
            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down
            current_row += 1 if going_down else -1
        return ''.join(rows)
    
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "PAYPALISHIRING"
    numRows1 = 3
    print(f"Example 1: {solution.convert(s1, numRows1)}")  # Expected: "PAHNAPLSIIGYIR"
    
    # Example 2
    s2 = "PAYPALISHIRING"
    numRows2 = 4
    print(f"Example 2: {solution.convert(s2, numRows2)}")  # Expected: "PINALSIGYAHRPI"
    
    # Example 3
    s3 = "A"
    numRows3 = 1
    print(f"Example 3: {solution.convert(s3, numRows3)}")  # Expected: "A"
    
    # Edge case: numRows = 2
    s4 = "ABCDE"
    numRows4 = 2
    print(f"Example 4: {solution.convert(s4, numRows4)}")  # Expected: "ACEBD"
    # Pattern: A C E
    #          B D
    
    # Edge case: numRows >= len(s)
    s5 = "ABC"
    numRows5 = 5
    print(f"Example 5: {solution.convert(s5, numRows5)}")  # Expected: "ABC"
    
    # Test with numRows = 5
    s6 = "ABCDEFGHIJKLMNO"
    numRows6 = 5
    print(f"Example 6: {solution.convert(s6, numRows6)}")
    # Pattern: A     I
    #          B   H J   N
    #          C G  K M  O
    #          D F  L
    #          E
    # Expected: "AIBHJNC GKMODEFL"
    
    # Test mathematical approach
    s7 = "PAYPALISHIRING"
    numRows7 = 3
    print(f"Example 7 (mathematical): {solution.convertMathematical(s7, numRows7)}")  # Expected: "PAHNAPLSIIGYIR"
    
    # Test mathematical approach with numRows = 4
    s8 = "PAYPALISHIRING"
    numRows8 = 4
    print(f"Example 8 (mathematical): {solution.convertMathematical(s8, numRows8)}")  # Expected: "PINALSIGYAHRPI"
