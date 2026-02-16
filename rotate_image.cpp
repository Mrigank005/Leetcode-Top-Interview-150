/*
48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You must rotate the image in-place.

Time Complexity: O(n²) - Must visit each element
Space Complexity: O(1) - In-place rotation
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
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
void testRotateImage() {
    Solution solution;
    
    // Test case 1: 3x3 matrix (Example 1)
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix1);
    vector<vector<int>> expected1 = {{7,4,1},{8,5,2},{9,6,3}};
    assert(matricesEqual(matrix1, expected1));
    cout << "Test 1 passed: 3x3 matrix (Transpose + Reverse)" << endl;
    
    // Test case 2: 4x4 matrix (Example 2)
    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    solution.rotate(matrix2);
    vector<vector<int>> expected2 = {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    assert(matricesEqual(matrix2, expected2));
    cout << "Test 2 passed: 4x4 matrix" << endl;
    
    // Test case 3: 1x1 matrix
    vector<vector<int>> matrix3 = {{1}};
    solution.rotate(matrix3);
    vector<vector<int>> expected3 = {{1}};
    assert(matricesEqual(matrix3, expected3));
    cout << "Test 3 passed: 1x1 matrix" << endl;
    
    // Test case 4: 2x2 matrix
    vector<vector<int>> matrix4 = {{1,2},{3,4}};
    solution.rotate(matrix4);
    vector<vector<int>> expected4 = {{3,1},{4,2}};
    assert(matricesEqual(matrix4, expected4));
    cout << "Test 4 passed: 2x2 matrix" << endl;
    
    // Test case 5: 5x5 matrix
    vector<vector<int>> matrix5 = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    solution.rotate(matrix5);
    vector<vector<int>> expected5 = {
        {21, 16, 11, 6, 1},
        {22, 17, 12, 7, 2},
        {23, 18, 13, 8, 3},
        {24, 19, 14, 9, 4},
        {25, 20, 15, 10, 5}
    };
    assert(matricesEqual(matrix5, expected5));
    cout << "Test 5 passed: 5x5 matrix" << endl;
    
    // Test case 6: Matrix with negative numbers
    vector<vector<int>> matrix6 = {{-1,-2},{-3,-4}};
    solution.rotate(matrix6);
    vector<vector<int>> expected6 = {{-3,-1},{-4,-2}};
    assert(matricesEqual(matrix6, expected6));
    cout << "Test 6 passed: Matrix with negative numbers" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testRotateImage();
    return 0;
}
