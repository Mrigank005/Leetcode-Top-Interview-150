"""
289. Game of Life

According to Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Rules:
1. Any live cell with fewer than two live neighbors dies (under-population).
2. Any live cell with two or three live neighbors lives on.
3. Any live cell with more than three live neighbors dies (over-population).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

All updates happen simultaneously.

Time Complexity: O(m * n)
Space Complexity: O(1) for in-place solution
"""

from typing import List

class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        if not board or not board[0]:
            return
        
        m, n = len(board), len(board[0])
        
        directions = [(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]
        
        for i in range(m):
            for j in range(n):
                live_neighbors = 0
                
                for di, dj in directions:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < m and 0 <= nj < n:
                        if board[ni][nj] == 1 or board[ni][nj] == 3:
                            live_neighbors += 1
                
                if board[i][j] == 1:
                    if live_neighbors < 2 or live_neighbors > 3:
                        board[i][j] = 3 
                else:
                    if live_neighbors == 3:
                        board[i][j] = 2
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 1 
                elif board[i][j] == 3:
                    board[i][j] = 0 
                    
# Test cases
def test_game_of_life():
    solution = Solution()
    
    # Test case 1: Example 1
    board1 = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    solution.gameOfLife(board1)
    expected1 = [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
    assert board1 == expected1
    print("Test 1 passed: Example 1 (In-place)")
    
    # Test case 2: Example 1 with copy approach
    board1b = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    solution.gameOfLife_copy(board1b)
    assert board1b == expected1
    print("Test 2 passed: Example 1 (Copy)")
    
    # Test case 3: Example 1 with bit manipulation
    board1c = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    solution.gameOfLife_bit_manipulation(board1c)
    assert board1c == expected1
    print("Test 3 passed: Example 1 (Bit Manipulation)")
    
    # Test case 4: Example 2
    board2 = [[1,1],[1,0]]
    solution.gameOfLife(board2)
    expected2 = [[1,1],[1,1]]
    assert board2 == expected2
    print("Test 4 passed: Example 2")
    
    # Test case 5: All dead cells
    board3 = [[0,0,0],[0,0,0],[0,0,0]]
    solution.gameOfLife(board3)
    expected3 = [[0,0,0],[0,0,0],[0,0,0]]
    assert board3 == expected3
    print("Test 5 passed: All dead cells")
    
    # Test case 6: All alive cells (over-population)
    board4 = [[1,1,1],[1,1,1],[1,1,1]]
    solution.gameOfLife(board4)
    expected4 = [[1,0,1],[0,0,0],[1,0,1]]
    assert board4 == expected4
    print("Test 6 passed: All alive cells (over-population)")
    
    # Test case 7: Single cell alive (under-population)
    board5 = [[0,0,0],[0,1,0],[0,0,0]]
    solution.gameOfLife(board5)
    expected5 = [[0,0,0],[0,0,0],[0,0,0]]
    assert board5 == expected5
    print("Test 7 passed: Single cell alive (under-population)")
    
    # Test case 8: Blinker pattern (oscillator)
    board6 = [[0,1,0],[0,1,0],[0,1,0]]
    solution.gameOfLife(board6)
    expected6 = [[0,0,0],[1,1,1],[0,0,0]]
    assert board6 == expected6
    print("Test 8 passed: Blinker pattern")
    
    # Test case 9: Block pattern (still life)
    board7 = [[1,1],[1,1]]
    solution.gameOfLife(board7)
    expected7 = [[1,1],[1,1]]
    assert board7 == expected7
    print("Test 9 passed: Block pattern (still life)")
    
    # Test case 10: Single row
    board8 = [[1,1,1]]
    solution.gameOfLife(board8)
    expected8 = [[0,1,0]]
    assert board8 == expected8
    print("Test 10 passed: Single row")
    
    # Test case 11: Single column
    board9 = [[1],[1],[1]]
    solution.gameOfLife(board9)
    expected9 = [[0],[1],[0]]
    assert board9 == expected9
    print("Test 11 passed: Single column")
    
    # Test case 12: 1x1 board alive
    board10 = [[1]]
    solution.gameOfLife(board10)
    expected10 = [[0]]
    assert board10 == expected10
    print("Test 12 passed: 1x1 board alive")
    
    # Test case 13: 1x1 board dead
    board11 = [[0]]
    solution.gameOfLife(board11)
    expected11 = [[0]]
    assert board11 == expected11
    print("Test 13 passed: 1x1 board dead")
    
    print("\nAll test cases passed!")


if __name__ == "__main__":
    test_game_of_life()
