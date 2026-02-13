/*
76. Minimum Window Substring

Time Complexity: O(m + n) where m = len(s), n = len(t)
Space Complexity: O(m + n) for the hashmaps
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {        
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        int required = tFreq.size();
        unordered_map<char, int> windowFreq;
        int formed = 0; 
        int left = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            windowFreq[c]++;
            
            if (tFreq.find(c) != tFreq.end() && windowFreq[c] == tFreq[c]) {
                formed++;
            }
            while (formed == required && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (tFreq.find(leftChar) != tFreq.end() && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: '" << solution.minWindow("ADOBECODEBANC", "ABC") << "'" << endl;  // Expected: "BANC"
    
    // Example 2
    cout << "Example 2: '" << solution.minWindow("a", "a") << "'" << endl;  // Expected: "a"
    
    // Example 3
    cout << "Example 3: '" << solution.minWindow("a", "aa") << "'" << endl;  // Expected: ""
    
    // Edge case: t longer than s
    cout << "Example 4: '" << solution.minWindow("ab", "abc") << "'" << endl;  // Expected: ""
    
    // Edge case: exact match
    cout << "Example 5: '" << solution.minWindow("abc", "abc") << "'" << endl;  // Expected: "abc"
    
    // Edge case: multiple windows
    cout << "Example 6: '" << solution.minWindow("aaabbbccc", "abc") << "'" << endl;  // Expected: "abbc" or similar
    
    // Edge case: with duplicates
    cout << "Example 7: '" << solution.minWindow("ADOBECODEBANC", "AABC") << "'" << endl;  // Expected: "ADOBEC" or similar
    
    // Edge case: t has duplicate characters
    cout << "Example 8: '" << solution.minWindow("aabbcc", "abc") << "'" << endl;  // Expected: "abbc" or similar
    
    // Edge case: no common characters
    cout << "Example 9: '" << solution.minWindow("abc", "xyz") << "'" << endl;  // Expected: ""
    
    // Edge case: entire string is minimum
    cout << "Example 10: '" << solution.minWindow("abc", "cba") << "'" << endl;  // Expected: "abc"
    
    return 0;
}
