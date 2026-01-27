/*
13. Roman to Integer

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.romanToInt("III") << endl;  // Expected: 3
    
    // Example 2
    cout << "Example 2: " << solution.romanToInt("LVIII") << endl;  // Expected: 58
    
    // Example 3
    cout << "Example 3: " << solution.romanToInt("MCMXCIV") << endl;  // Expected: 1994
    
    // Edge case: single character
    cout << "Example 4: " << solution.romanToInt("M") << endl;  // Expected: 1000
    
    // Edge case: IV (subtraction case)
    cout << "Example 5: " << solution.romanToInt("IV") << endl;  // Expected: 4
    
    // Edge case: IX (subtraction case)
    cout << "Example 6: " << solution.romanToInt("IX") << endl;  // Expected: 9
    
    // All subtraction cases
    cout << "Example 7: " << solution.romanToInt("CDXLIV") << endl;  // Expected: 444
    
    // Maximum value
    cout << "Example 8: " << solution.romanToInt("MMMCMXCIX") << endl;  // Expected: 3999
    
    // Simple addition
    cout << "Example 9: " << solution.romanToInt("XXVII") << endl;  // Expected: 27
    
    // Complex mix
    cout << "Example 10: " << solution.romanToInt("DCXXI") << endl;  // Expected: 621
    
    return 0;
}
