/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Time Complexity: O(m * n) - Visit each element once
Space Complexity: O(1) - Not counting output array, O(m*n) if counting output
*/

#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;
            
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

bool vectorsEqual(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Test cases
void testSpiralMatrix() {
    Solution solution;
    
    // Test case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> expected1 = {1,2,3,6,9,8,7,4,5};
    assert(vectorsEqual(solution.spiralOrder(matrix1), expected1));
    cout << "Test 1 passed: 3x3 matrix" << endl;
    
    // Test case 2: 3x4 matrix
    vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> expected2 = {1,2,3,4,8,12,11,10,9,5,6,7};
    assert(vectorsEqual(solution.spiralOrder(matrix2), expected2));
    cout << "Test 2 passed: 3x4 matrix" << endl;
    
    // Test case 3: 1x1 matrix
    vector<vector<int>> matrix3 = {{1}};
    vector<int> expected3 = {1};
    assert(vectorsEqual(solution.spiralOrder(matrix3), expected3));
    cout << "Test 3 passed: 1x1 matrix" << endl;
    
    // Test case 4: Single row
    vector<vector<int>> matrix4 = {{1,2,3,4,5}};
    vector<int> expected4 = {1,2,3,4,5};
    assert(vectorsEqual(solution.spiralOrder(matrix4), expected4));
    cout << "Test 4 passed: Single row" << endl;
    
    // Test case 5: Single column
    vector<vector<int>> matrix5 = {{1},{2},{3},{4},{5}};
    vector<int> expected5 = {1,2,3,4,5};
    assert(vectorsEqual(solution.spiralOrder(matrix5), expected5));
    cout << "Test 5 passed: Single column" << endl;
    
    // Test case 6: 2x2 matrix
    vector<vector<int>> matrix6 = {{1,2},{3,4}};
    vector<int> expected6 = {1,2,4,3};
    assert(vectorsEqual(solution.spiralOrder(matrix6), expected6));
    cout << "Test 6 passed: 2x2 matrix" << endl;
    
    // Test case 7: 4x3 matrix (more rows than columns)
    vector<vector<int>> matrix7 = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> expected7 = {1,2,3,6,9,12,11,10,7,4,5,8};
    assert(vectorsEqual(solution.spiralOrder(matrix7), expected7));
    cout << "Test 7 passed: 4x3 matrix" << endl;
    
    // Test case 8: 2x3 matrix
    vector<vector<int>> matrix8 = {{1,2,3},{4,5,6}};
    vector<int> expected8 = {1,2,3,6,5,4};
    assert(vectorsEqual(solution.spiralOrder(matrix8), expected8));
    cout << "Test 8 passed: 2x3 matrix" << endl;
    
    // Test case 9: 3x2 matrix
    vector<vector<int>> matrix9 = {{1,2},{3,4},{5,6}};
    vector<int> expected9 = {1,2,4,6,5,3};
    assert(vectorsEqual(solution.spiralOrder(matrix9), expected9));
    cout << "Test 9 passed: 3x2 matrix" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testSpiralMatrix();
    return 0;
}
