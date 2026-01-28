/*
12. Integer to Roman

Time Complexity: O(1) - at most 13 symbols, each used at most 3-4 times
Space Complexity: O(1) - constant space for mapping
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
            for (int i = 0; i < values.size(); i++) {
            int count = num / values[i];
            if (count) {
                for (int j = 0; j < count; j++) {
                    result += symbols[i];
                }
                num -= values[i] * count;
            }
        }
        return result;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.intToRoman(3749) << endl;  // Expected: "MMMDCCXLIX"
    
    // Example 2
    cout << "Example 2: " << solution.intToRoman(58) << endl;  // Expected: "LVIII"
    
    // Example 3
    cout << "Example 3: " << solution.intToRoman(1994) << endl;  // Expected: "MCMXCIV"
    
    // Edge case: minimum value
    cout << "Example 4: " << solution.intToRoman(1) << endl;  // Expected: "I"
    
    // Edge case: maximum value
    cout << "Example 5: " << solution.intToRoman(3999) << endl;  // Expected: "MMMCMXCIX"
    
    // All subtractive forms
    cout << "Example 6: " << solution.intToRoman(444) << endl;  // Expected: "CDXLIV"
    
    // Simple values
    cout << "Example 7: " << solution.intToRoman(27) << endl;  // Expected: "XXVII"
    
    // Only subtractive forms
    cout << "Example 8: " << solution.intToRoman(49) << endl;  // Expected: "XLIX"
   
    // Edge case: round thousands
    cout << "Example 10: " << solution.intToRoman(3000) << endl;  // Expected: "MMM"
    
    return 0;
}
