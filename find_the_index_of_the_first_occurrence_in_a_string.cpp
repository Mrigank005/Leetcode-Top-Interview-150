/*
28. Find the Index of the First Occurrence in a String

Time Complexity: O(n * m)
Space Complexity: O(1)
where n = len(haystack), m = len(needle)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }        
        int n = haystack.length();
        int m = needle.length();
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }        
        return -1;
    }
    
    int strStrBuiltIn(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        return (pos != string::npos) ? pos : -1;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.strStr("sadbutsad", "sad") << endl;  // Expected: 0
    
    // Example 2
    cout << "Example 2: " << solution.strStr("leetcode", "leeto") << endl;  // Expected: -1
    
    // Edge case: needle at end
    cout << "Example 3: " << solution.strStr("hello", "llo") << endl;  // Expected: 2
    
    // Edge case: needle is entire haystack
    cout << "Example 4: " << solution.strStr("test", "test") << endl;  // Expected: 0
    
    // Edge case: single character
    cout << "Example 5: " << solution.strStr("a", "a") << endl;  // Expected: 0
    
    // Edge case: needle longer than haystack
    cout << "Example 6: " << solution.strStr("ab", "abc") << endl;  // Expected: -1
    
    // Edge case: multiple occurrences
    cout << "Example 7: " << solution.strStr("ababcaababcaabc", "ababcaabc") << endl;  // Expected: 6
    
    // Test built-in method
    cout << "Example 8 (built-in): " << solution.strStrBuiltIn("sadbutsad", "sad") << endl;  // Expected: 0
   
    return 0;
}
