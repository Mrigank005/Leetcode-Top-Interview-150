"""
48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You must rotate the image in-place.

Time Complexity: O(n²) - Must visit each element
Space Complexity: O(1) - In-place rotation
"""

from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(n):
            matrix[i].reverse()
    
# Test cases
def test_rotate_image():
    solution = Solution()
    
    # Test case 1: 3x3 matrix (Example 1)
    matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
    solution.rotate(matrix1)
    expected1 = [[7,4,1],[8,5,2],[9,6,3]]
    assert matrix1 == expected1
    print("Test 1 passed: 3x3 matrix (Transpose + Reverse)")
    
    # Test case 2: 4x4 matrix (Example 2)
    matrix2 = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    solution.rotate(matrix2)
    expected2 = [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    assert matrix2 == expected2
    print("Test 2 passed: 4x4 matrix")
    
    # Test case 3: 1x1 matrix
    matrix3 = [[1]]
    solution.rotate(matrix3)
    assert matrix3 == [[1]]
    print("Test 3 passed: 1x1 matrix")
    
    # Test case 4: 2x2 matrix
    matrix4 = [[1,2],[3,4]]
    solution.rotate(matrix4)
    expected4 = [[3,1],[4,2]]
    assert matrix4 == expected4
    print("Test 4 passed: 2x2 matrix")
    
    # Test case 5: 5x5 matrix
    matrix5 = [
        [1, 2, 3, 4, 5],
        [6, 7, 8, 9, 10],
        [11, 12, 13, 14, 15],
        [16, 17, 18, 19, 20],
        [21, 22, 23, 24, 25]
    ]
    solution.rotate(matrix5)
    expected5 = [
        [21, 16, 11, 6, 1],
        [22, 17, 12, 7, 2],
        [23, 18, 13, 8, 3],
        [24, 19, 14, 9, 4],
        [25, 20, 15, 10, 5]
    ]
    assert matrix5 == expected5
    print("Test 5 passed: 5x5 matrix")
    
    # Test case 6: Matrix with negative numbers
    matrix6 = [[-1,-2],[-3,-4]]
    solution.rotate(matrix6)
    expected6 = [[-3,-1],[-4,-2]]
    assert matrix6 == expected6
    print("Test 6 passed: Matrix with negative numbers")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_rotate_image()
