/*
58. Length of Last Word

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.lengthOfLastWord("Hello World") << endl;  // Expected: 5
    
    // Example 2
    cout << "Example 2: " << solution.lengthOfLastWord("   fly me   to   the moon  ") << endl;  // Expected: 4
    
    // Example 3
    cout << "Example 3: " << solution.lengthOfLastWord("luffy is still joyboy") << endl;  // Expected: 6
    
    // Edge case: single word
    cout << "Example 4: " << solution.lengthOfLastWord("Hello") << endl;  // Expected: 5
    
    // Edge case: single word with trailing spaces
    cout << "Example 5: " << solution.lengthOfLastWord("a   ") << endl;  // Expected: 1
    
    // Edge case: single word with leading spaces
    cout << "Example 6: " << solution.lengthOfLastWord("   a") << endl;  // Expected: 1
    
    // Edge case: multiple spaces between words
    cout << "Example 7: " << solution.lengthOfLastWord("a  b    c") << endl;  // Expected: 1
    
    // Edge case: long last word
    cout << "Example 8: " << solution.lengthOfLastWord("a programming") << endl;  // Expected: 11
   
    return 0;
}
