"""
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Time Complexity: O(m * n) - Visit each element once
Space Complexity: O(1) - Not counting output array, O(m*n) if counting output
"""

from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix or not matrix[0]:
            return []
        
        result = []
        m, n = len(matrix), len(matrix[0])
        
        top, bottom = 0, m - 1
        left, right = 0, n - 1
        
        while top <= bottom and left <= right:
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1
            
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1
            
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1
            
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1
        
        return result

# Test cases
def test_spiral_matrix():
    solution = Solution()
    
    # Test case 1: 3x3 matrix (Example 1)
    matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
    expected1 = [1,2,3,6,9,8,7,4,5]
    assert solution.spiralOrder(matrix1) == expected1
    print("Test 1 passed: 3x3 matrix")
    
    # Test case 2: 3x4 matrix (Example 2)
    matrix2 = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    expected2 = [1,2,3,4,8,12,11,10,9,5,6,7]
    assert solution.spiralOrder(matrix2) == expected2
    
    # Test case 3: 1x1 matrix
    matrix3 = [[1]]
    expected3 = [1]
    assert solution.spiralOrder(matrix3) == expected3
    print("Test 3 passed: 1x1 matrix")
    
    # Test case 4: Single row
    matrix4 = [[1,2,3,4,5]]
    expected4 = [1,2,3,4,5]
    assert solution.spiralOrder(matrix4) == expected4
    print("Test 4 passed: Single row")
    
    # Test case 5: Single column
    matrix5 = [[1],[2],[3],[4],[5]]
    expected5 = [1,2,3,4,5]
    assert solution.spiralOrder(matrix5) == expected5
    print("Test 5 passed: Single column")
    
    # Test case 6: 2x2 matrix
    matrix6 = [[1,2],[3,4]]
    expected6 = [1,2,4,3]
    assert solution.spiralOrder(matrix6) == expected6
    
    # Test case 7: 4x3 matrix (more rows than columns)
    matrix7 = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
    expected7 = [1,2,3,6,9,12,11,10,7,4,5,8]
    assert solution.spiralOrder(matrix7) == expected7
    print("Test 7 passed: 4x3 matrix")
    
    # Test case 8: 2x3 matrix
    matrix8 = [[1,2,3],[4,5,6]]
    expected8 = [1,2,3,6,5,4]
    assert solution.spiralOrder(matrix8) == expected8
    print("Test 8 passed: 2x3 matrix")
    
    # Test case 9: 3x2 matrix
    matrix9 = [[1,2],[3,4],[5,6]]
    expected9 = [1,2,4,6,5,3]
    assert solution.spiralOrder(matrix9) == expected9
    print("Test 9 passed: 3x2 matrix")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_spiral_matrix()
