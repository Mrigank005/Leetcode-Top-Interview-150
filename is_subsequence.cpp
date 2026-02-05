/*
392. Is Subsequence

Time Complexity: O(n) where n is length of t
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        
        int i = 0;  // Pointer for s
        
        for (char c : t) {
            if (c == s[i]) {
                i++;
                if (i == s.length()) {
                    return true;
                }
            }
        }
        
        return false;
    }
};




// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << (solution.isSubsequence("abc", "ahbgdc") ? "true" : "false") << endl;  // Expected: true
    
    // Example 2
    cout << "Example 2: " << (solution.isSubsequence("axc", "ahbgdc") ? "true" : "false") << endl;  // Expected: false
    
    // Edge case: empty s
    cout << "Example 3: " << (solution.isSubsequence("", "ahbgdc") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: empty t
    cout << "Example 4: " << (solution.isSubsequence("abc", "") ? "true" : "false") << endl;  // Expected: false
    
    // Edge case: both empty
    cout << "Example 5: " << (solution.isSubsequence("", "") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: s equals t
    cout << "Example 6: " << (solution.isSubsequence("abc", "abc") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: single character match
    cout << "Example 7: " << (solution.isSubsequence("b", "abc") ? "true" : "false") << endl;  // Expected: true

    return 0;
}
