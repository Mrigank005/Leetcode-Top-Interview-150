/*
14. Longest Common Prefix

Time Complexity: O(S) where S is sum of all characters in all strings
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Example 1: '" << solution.longestCommonPrefix(strs1) << "'" << endl;  // Expected: "fl"
    
    // Example 2
    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Example 2: '" << solution.longestCommonPrefix(strs2) << "'" << endl;  // Expected: ""
    
    // Edge case: single string
    vector<string> strs3 = {"alone"};
    cout << "Example 3: '" << solution.longestCommonPrefix(strs3) << "'" << endl;  // Expected: "alone"
    
    // Edge case: all strings identical
    vector<string> strs4 = {"test", "test", "test"};
    cout << "Example 4: '" << solution.longestCommonPrefix(strs4) << "'" << endl;  // Expected: "test"
    
    // Edge case: empty string in array
    vector<string> strs5 = {"", "b"};
    cout << "Example 5: '" << solution.longestCommonPrefix(strs5) << "'" << endl;  // Expected: ""
    
    // Edge case: first string is prefix of all
    vector<string> strs6 = {"a", "ab", "abc"};
    cout << "Example 6: '" << solution.longestCommonPrefix(strs6) << "'" << endl;  // Expected: "a"
    
    // Edge case: no common prefix from start
    vector<string> strs7 = {"abc", "bcd", "cde"};
    cout << "Example 7: '" << solution.longestCommonPrefix(strs7) << "'" << endl;  // Expected: ""
     
    // Edge case: longer common prefix
    vector<string> strs10 = {"interspecies", "interstellar", "interstate"};
    cout << "Example 10: '" << solution.longestCommonPrefix(strs10) << "'" << endl;  // Expected: "inters"
    
    return 0;
}
