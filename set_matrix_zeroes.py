"""
73. Set Matrix Zeroes

Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Time Complexity: O(m * n)
Space Complexity: O(1) for optimal solution
"""

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        if not matrix or not matrix[0]:
            return
        m, n = len(matrix), len(matrix[0])
        first_row_has_zero = False
        first_col_has_zero = False
        for j in range(n):
            if matrix[0][j] == 0:
                first_row_has_zero = True
                break
        for i in range(m):
            if matrix[i][0] == 0:
                first_col_has_zero = True
                break
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if first_row_has_zero:
            for j in range(n):
                matrix[0][j] = 0
        if first_col_has_zero:
            for i in range(m):
                matrix[i][0] = 0
    

# Test cases
def test_set_matrix_zeroes():
    solution = Solution()
    
    # Test case 1: 3x3 matrix (Example 1)
    matrix1 = [[1,1,1],[1,0,1],[1,1,1]]
    solution.setZeroes(matrix1)
    expected1 = [[1,0,1],[0,0,0],[1,0,1]]
    assert matrix1 == expected1
    print("Test 1 passed: 3x3 matrix")
    
    # Test case 2: 3x4 matrix (Example 2)
    matrix2 = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    solution.setZeroes(matrix2)
    expected2 = [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
    assert matrix2 == expected2
    print("Test 2 passed: 3x4 matrix")
    
    # Test case 3: Single row
    matrix3 = [[1,2,0,4]]
    solution.setZeroes(matrix3)
    expected3 = [[0,0,0,0]]
    assert matrix3 == expected3
    print("Test 3 passed: Single row")
    
    # Test case 4: Single column
    matrix4 = [[1],[0],[3]]
    solution.setZeroes(matrix4)
    expected4 = [[0],[0],[0]]
    assert matrix4 == expected4
    print("Test 4 passed: Single column")
    
    # Test case 5: All zeros
    matrix5 = [[0,0],[0,0]]
    solution.setZeroes(matrix5)
    expected5 = [[0,0],[0,0]]
    assert matrix5 == expected5
    print("Test 5 passed: All zeros")
    
    # Test case 6: No zeros
    matrix6 = [[1,2,3],[4,5,6]]
    solution.setZeroes(matrix6)
    expected6 = [[1,2,3],[4,5,6]]
    assert matrix6 == expected6
    print("Test 6 passed: No zeros")
    
    # Test case 7: Zero in first row
    matrix7 = [[1,0,3],[4,5,6],[7,8,9]]
    solution.setZeroes(matrix7)
    expected7 = [[0,0,0],[4,0,6],[7,0,9]]
    assert matrix7 == expected7
    print("Test 7 passed: Zero in first row")
    
    # Test case 8: Zero in first column
    matrix8 = [[1,2,3],[0,5,6],[7,8,9]]
    solution.setZeroes(matrix8)
    expected8 = [[0,2,3],[0,0,0],[0,8,9]]
    assert matrix8 == expected8
    print("Test 8 passed: Zero in first column")
    
    # Test case 9: Zero at (0,0)
    matrix9 = [[0,2,3],[4,5,6],[7,8,9]]
    solution.setZeroes(matrix9)
    expected9 = [[0,0,0],[0,5,6],[0,8,9]]
    assert matrix9 == expected9
    print("Test 9 passed: Zero at (0,0)")
    
    # Test case 10: Multiple zeros
    matrix10 = [[1,0,3],[0,5,0],[7,8,9]]
    solution.setZeroes(matrix10)
    expected10 = [[0,0,0],[0,0,0],[0,0,0]]
    assert matrix10 == expected10
    print("Test 10 passed: Multiple zeros")
    
    # Test case 11: 1x1 matrix with zero
    matrix11 = [[0]]
    solution.setZeroes(matrix11)
    expected11 = [[0]]
    assert matrix11 == expected11
    print("Test 11 passed: 1x1 matrix with zero")
    
    # Test case 12: 1x1 matrix without zero
    matrix12 = [[5]]
    solution.setZeroes(matrix12)
    expected12 = [[5]]
    assert matrix12 == expected12
    print("Test 12 passed: 1x1 matrix without zero")
    
    # Test case 13: The failing test case from LeetCode
    matrix13 = [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]
    solution.setZeroes(matrix13)
    expected13 = [[0,0,3,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    assert matrix13 == expected13
    print("Test 13 passed: LeetCode failing test case")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_set_matrix_zeroes()
