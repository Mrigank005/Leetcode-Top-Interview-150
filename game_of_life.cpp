/*
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
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        vector<pair<int, int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                for (const auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        if (board[ni][nj] == 1 || board[ni][nj] == 3) {
                            liveNeighbors++;
                        }
                    }
                }
                
                if (board[i][j] == 1) { 
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        board[i][j] = 3;  
                    }
                } else { 
                    if (liveNeighbors == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1; 
                } else if (board[i][j] == 3) {
                    board[i][j] = 0; 
                }
            }
        }
    }
};

// Helper function to check if two boards are equal
bool boardsEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i].size() != b[i].size()) return false;
        for (size_t j = 0; j < a[i].size(); j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// Test cases
void testGameOfLife() {
    Solution solution;
    
    // Test case 1: Example 1
    vector<vector<int>> board1 = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    solution.gameOfLife(board1);
    vector<vector<int>> expected1 = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
    assert(boardsEqual(board1, expected1));
    cout << "Test 1 passed: Example 1 (In-place)" << endl;
    
    // Test case 2: Example 2
    vector<vector<int>> board2 = {{1,1},{1,0}};
    solution.gameOfLife(board2);
    vector<vector<int>> expected2 = {{1,1},{1,1}};
    assert(boardsEqual(board2, expected2));
    cout << "Test 2 passed: Example 2" << endl;
    
    // Test case 3: All dead cells
    vector<vector<int>> board3 = {{0,0,0},{0,0,0},{0,0,0}};
    solution.gameOfLife(board3);
    vector<vector<int>> expected3 = {{0,0,0},{0,0,0},{0,0,0}};
    assert(boardsEqual(board3, expected3));
    cout << "Test 3 passed: All dead cells" << endl;
    
    // Test case 4: All alive cells (over-population)
    vector<vector<int>> board4 = {{1,1,1},{1,1,1},{1,1,1}};
    solution.gameOfLife(board4);
    vector<vector<int>> expected4 = {{1,0,1},{0,0,0},{1,0,1}};
    assert(boardsEqual(board4, expected4));
    cout << "Test 4 passed: All alive cells (over-population)" << endl;
    
    // Test case 5: Single cell alive (under-population)
    vector<vector<int>> board5 = {{0,0,0},{0,1,0},{0,0,0}};
    solution.gameOfLife(board5);
    vector<vector<int>> expected5 = {{0,0,0},{0,0,0},{0,0,0}};
    assert(boardsEqual(board5, expected5));
    cout << "Test 5 passed: Single cell alive (under-population)" << endl;
    
    // Test case 6: Blinker pattern (oscillator)
    vector<vector<int>> board6 = {{0,1,0},{0,1,0},{0,1,0}};
    solution.gameOfLife(board6);
    vector<vector<int>> expected6 = {{0,0,0},{1,1,1},{0,0,0}};
    assert(boardsEqual(board6, expected6));
    cout << "Test 6 passed: Blinker pattern" << endl;
    
    // Test case 7: Block pattern (still life)
    vector<vector<int>> board7 = {{1,1},{1,1}};
    solution.gameOfLife(board7);
    vector<vector<int>> expected7 = {{1,1},{1,1}};
    assert(boardsEqual(board7, expected7));
    cout << "Test 7 passed: Block pattern (still life)" << endl;
    
    // Test case 8: Single row
    vector<vector<int>> board8 = {{1,1,1}};
    solution.gameOfLife(board8);
    vector<vector<int>> expected8 = {{0,1,0}};
    assert(boardsEqual(board8, expected8));
    cout << "Test 8 passed: Single row" << endl;
    
    // Test case 9: Single column
    vector<vector<int>> board9 = {{1},{1},{1}};
    solution.gameOfLife(board9);
    vector<vector<int>> expected9 = {{0},{1},{0}};
    assert(boardsEqual(board9, expected9));
    cout << "Test 9 passed: Single column" << endl;
    
    // Test case 10: 1x1 board alive
    vector<vector<int>> board10 = {{1}};
    solution.gameOfLife(board10);
    vector<vector<int>> expected10 = {{0}};
    assert(boardsEqual(board10, expected10));
    cout << "Test 10 passed: 1x1 board alive" << endl;
    
    // Test case 11: 1x1 board dead
    vector<vector<int>> board11 = {{0}};
    solution.gameOfLife(board11);
    vector<vector<int>> expected11 = {{0}};
    assert(boardsEqual(board11, expected11));
    cout << "Test 11 passed: 1x1 board dead" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testGameOfLife();
    return 0;
}
