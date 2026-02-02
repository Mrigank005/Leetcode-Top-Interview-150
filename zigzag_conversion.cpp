/*
6. Zigzag Conversion

Time Complexity: O(n) where n is length of string
Space Complexity: O(n) for storing rows
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.convert("PAYPALISHIRING", 3) << endl;  // Expected: "PAHNAPLSIIGYIR"
    
    // Example 2
    cout << "Example 2: " << solution.convert("PAYPALISHIRING", 4) << endl;  // Expected: "PINALSIGYAHRPI"
    
    // Example 3
    cout << "Example 3: " << solution.convert("A", 1) << endl;  // Expected: "A"
    
    // Edge case: numRows = 2
    cout << "Example 4: " << solution.convert("ABCDE", 2) << endl;  // Expected: "ACEBD"
    
    // Edge case: numRows >= len(s)
    cout << "Example 5: " << solution.convert("ABC", 5) << endl;  // Expected: "ABC"
    
    // Test with numRows = 5
    cout << "Example 6: " << solution.convert("ABCDEFGHIJKLMNO", 5) << endl;

    return 0;
}
