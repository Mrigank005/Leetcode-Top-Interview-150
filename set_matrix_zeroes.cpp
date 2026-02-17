/*
73. Set Matrix Zeroes

Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Time Complexity: O(m * n)
Space Complexity: O(1) for optimal solution
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowHasZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColHasZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

bool matricesEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
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
void testSetMatrixZeroes() {
    Solution solution;
    
    // Test case 1: 3x3 matrix (Example 1)
    vector<vector<int>> matrix1 = {{1,1,1},{1,0,1},{1,1,1}};
    solution.setZeroes(matrix1);
    vector<vector<int>> expected1 = {{1,0,1},{0,0,0},{1,0,1}};
    assert(matricesEqual(matrix1, expected1));
    cout << "Test 1 passed: 3x3 matrix" << endl;
    
    // Test case 2: 3x4 matrix (Example 2)
    vector<vector<int>> matrix2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix2);
    vector<vector<int>> expected2 = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    assert(matricesEqual(matrix2, expected2));
    cout << "Test 2 passed: 3x4 matrix" << endl;

    // Test case 3: Single row
    vector<vector<int>> matrix3 = {{1,2,0,4}};
    solution.setZeroes(matrix3);
    vector<vector<int>> expected3 = {{0,0,0,0}};
    assert(matricesEqual(matrix3, expected3));
    cout << "Test 3 passed: Single row" << endl;
    
    // Test case 4: Single column
    vector<vector<int>> matrix4 = {{1},{0},{3}};
    solution.setZeroes(matrix4);
    vector<vector<int>> expected4 = {{0},{0},{0}};
    assert(matricesEqual(matrix4, expected4));
    cout << "Test 4 passed: Single column" << endl;
    
    // Test case 5: All zeros
    vector<vector<int>> matrix5 = {{0,0},{0,0}};
    solution.setZeroes(matrix5);
    vector<vector<int>> expected5 = {{0,0},{0,0}};
    assert(matricesEqual(matrix5, expected5));
    cout << "Test 5 passed: All zeros" << endl;
    
    // Test case 6: No zeros
    vector<vector<int>> matrix6 = {{1,2,3},{4,5,6}};
    solution.setZeroes(matrix6);
    vector<vector<int>> expected6 = {{1,2,3},{4,5,6}};
    assert(matricesEqual(matrix6, expected6));
    cout << "Test 6 passed: No zeros" << endl;
    
    // Test case 7: Zero in first row
    vector<vector<int>> matrix7 = {{1,0,3},{4,5,6},{7,8,9}};
    solution.setZeroes(matrix7);
    vector<vector<int>> expected7 = {{0,0,0},{4,0,6},{7,0,9}};
    assert(matricesEqual(matrix7, expected7));
    cout << "Test 7 passed: Zero in first row" << endl;
    
    // Test case 8: Zero in first column
    vector<vector<int>> matrix8 = {{1,2,3},{0,5,6},{7,8,9}};
    solution.setZeroes(matrix8);
    vector<vector<int>> expected8 = {{0,2,3},{0,0,0},{0,8,9}};
    assert(matricesEqual(matrix8, expected8));
    cout << "Test 8 passed: Zero in first column" << endl;
    
    // Test case 9: Zero at (0,0)
    vector<vector<int>> matrix9 = {{0,2,3},{4,5,6},{7,8,9}};
    solution.setZeroes(matrix9);
    vector<vector<int>> expected9 = {{0,0,0},{0,5,6},{0,8,9}};
    assert(matricesEqual(matrix9, expected9));
    cout << "Test 9 passed: Zero at (0,0)" << endl;
    
    // Test case 10: Multiple zeros
    vector<vector<int>> matrix10 = {{1,0,3},{0,5,0},{7,8,9}};
    solution.setZeroes(matrix10);
    vector<vector<int>> expected10 = {{0,0,0},{0,0,0},{0,0,0}};
    assert(matricesEqual(matrix10, expected10));
    cout << "Test 10 passed: Multiple zeros" << endl;
    
    // Test case 11: 1x1 matrix with zero
    vector<vector<int>> matrix11 = {{0}};
    solution.setZeroes(matrix11);
    vector<vector<int>> expected11 = {{0}};
    assert(matricesEqual(matrix11, expected11));
    cout << "Test 11 passed: 1x1 matrix with zero" << endl;
    
    // Test case 12: 1x1 matrix without zero
    vector<vector<int>> matrix12 = {{5}};
    solution.setZeroes(matrix12);
    vector<vector<int>> expected12 = {{5}};
    assert(matricesEqual(matrix12, expected12));
    cout << "Test 12 passed: 1x1 matrix without zero" << endl;
    
    // Test case 13: The failing test case from LeetCode
    vector<vector<int>> matrix13 = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    solution.setZeroes(matrix13);
    vector<vector<int>> expected13 = {{0,0,3,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    assert(matricesEqual(matrix13, expected13));
    cout << "Test 13 passed: LeetCode failing test case" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testSetMatrixZeroes();
    return 0;
}
