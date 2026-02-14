/*
36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated.

Rules:
1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes must contain the digits 1-9 without repetition.

Time Complexity: O(1) - Fixed 9x9 board, or O(n²) where n=9
Space Complexity: O(1) - Fixed size, or O(n²) where n=9
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char cell = board[r][c];
                if (cell == '.') {
                    continue;
                }
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (rows[r].count(cell) || cols[c].count(cell) || boxes[boxIndex].count(cell)) {
                    return false;
                }
                rows[r].insert(cell);
                cols[c].insert(cell);
                boxes[boxIndex].insert(cell);
            }
        }
        return true;
    }
};

// Test cases
void testValidSudoku() {
    Solution solution;
    
    // Test case 1: Valid board
    vector<vector<char>> board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    assert(solution.isValidSudoku(board1) == true);
    cout << "Test 1 passed: Valid board" << endl;
    
    // Test case 2: Invalid board - duplicate in 3x3 box
    vector<vector<char>> board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    assert(solution.isValidSudoku(board2) == false);
    cout << "Test 2 passed: Invalid board (duplicate in 3x3 box)" << endl;
    
    // Test case 3: Invalid board - duplicate in column
    vector<vector<char>> board3 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'5','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    assert(solution.isValidSudoku(board3) == false);
    cout << "Test 3 passed: Invalid board (duplicate in column)" << endl;
    
    // Test case 4: Invalid board - duplicate in row
    vector<vector<char>> board4 = {
        {'5','3','.','.','7','.','.','3','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    assert(solution.isValidSudoku(board4) == false);
    cout << "Test 4 passed: Invalid board (duplicate in row)" << endl;
    
    // Test case 5: Empty board
    vector<vector<char>> board5(9, vector<char>(9, '.'));
    assert(solution.isValidSudoku(board5) == true);
    cout << "Test 5 passed: Empty board is valid" << endl;
    
    // Test case 6: Board with single digit
    vector<vector<char>> board6(9, vector<char>(9, '.'));
    board6[0][0] = '5';
    assert(solution.isValidSudoku(board6) == true);
    cout << "Test 6 passed: Board with single digit" << endl;
    
    // Test case 7: Full valid row
    vector<vector<char>> board7(9, vector<char>(9, '.'));
    board7[0] = {'1','2','3','4','5','6','7','8','9'};
    assert(solution.isValidSudoku(board7) == true);
    cout << "Test 7 passed: Full valid row" << endl;
    
    // Test case 8: Invalid - duplicate in middle 3x3 box
    vector<vector<char>> board8(9, vector<char>(9, '.'));
    board8[3][3] = '5';
    board8[4][5] = '5';
    assert(solution.isValidSudoku(board8) == false);
    cout << "Test 8 passed: Invalid (duplicate in middle 3x3 box)" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testValidSudoku();
    return 0;
}
