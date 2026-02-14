"""
36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated.

Rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes must contain the digits 1-9 without repetition.

Time Complexity: O(1) - Fixed 9x9 board, or O(n²) where n=9
Space Complexity: O(1) - Fixed size, or O(n²) where n=9
"""

from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        
        for r in range(9):
            for c in range(9):
                cell = board[r][c]
                
                if cell == '.':
                    continue
                
                box_index = (r // 3) * 3 + (c // 3)
                
                if cell in rows[r] or cell in cols[c] or cell in boxes[box_index]:
                    return False
                
                rows[r].add(cell)
                cols[c].add(cell)
                boxes[box_index].add(cell)
        
        return True

# Test cases
def test_valid_sudoku():
    solution = Solution()
    
    # Test case 1: Valid board (Example 1)
    board1 = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert solution.isValidSudoku(board1) == True
    print("Test 1 passed: Valid board")
    
    # Test case 2: Invalid board - duplicate in row (Example 2)
    board2 = [
        ["8","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert solution.isValidSudoku(board2) == False
    print("Test 2 passed: Invalid board (duplicate in 3x3 box)")
    
    # Test case 3: Invalid board - duplicate in column
    board3 = [
        ["5","3",".",".","7",".",".",".","."],
        ["5",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert solution.isValidSudoku(board3) == False
    print("Test 3 passed: Invalid board (duplicate in column)")
    
    # Test case 4: Invalid board - duplicate in row
    board4 = [
        ["5","3",".",".","7",".",".","3","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    assert solution.isValidSudoku(board4) == False
    print("Test 4 passed: Invalid board (duplicate in row)")
    
    # Test case 5: Empty board (all dots)
    board5 = [["." for _ in range(9)] for _ in range(9)]
    assert solution.isValidSudoku(board5) == True
    print("Test 5 passed: Empty board is valid")
    
    # Test case 6: Board with single digit
    board6 = [["." for _ in range(9)] for _ in range(9)]
    board6[0][0] = "5"
    assert solution.isValidSudoku(board6) == True
    print("Test 6 passed: Board with single digit")
    
    # Test case 7: Full valid row
    board7 = [["." for _ in range(9)] for _ in range(9)]
    board7[0] = ["1","2","3","4","5","6","7","8","9"]
    assert solution.isValidSudoku(board7) == True
    print("Test 7 passed: Full valid row")
    
    # Test case 8: Invalid - duplicate in middle 3x3 box
    board8 = [
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".","5",".",".",".",".","."],
        [".",".",".",".",".","5",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."],
        [".",".",".",".",".",".",".",".","."]
    ]
    assert solution.isValidSudoku(board8) == False
    print("Test 8 passed: Invalid (duplicate in middle 3x3 box)")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_valid_sudoku()
