/*
3. Longest Substring Without Repeating Characters

Time Complexity: O(n)
Space Complexity: O(min(n, m)) where m is charset size
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Shrink window from left while duplicate exists
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << solution.lengthOfLongestSubstring("abcabcbb") << endl;  // Expected: 3
    // "abc"
    
    // Example 2
    cout << "Example 2: " << solution.lengthOfLongestSubstring("bbbbb") << endl;  // Expected: 1
    // "b"
    
    // Example 3
    cout << "Example 3: " << solution.lengthOfLongestSubstring("pwwkew") << endl;  // Expected: 3
    // "wke"
    
    // Edge case: empty string
    cout << "Example 4: " << solution.lengthOfLongestSubstring("") << endl;  // Expected: 0
    
    // Edge case: single character
    cout << "Example 5: " << solution.lengthOfLongestSubstring("a") << endl;  // Expected: 1
    
    // Edge case: all unique characters
    cout << "Example 6: " << solution.lengthOfLongestSubstring("abcdef") << endl;  // Expected: 6
    
    // Edge case: with spaces and symbols
    cout << "Example 7: " << solution.lengthOfLongestSubstring("a b c! @#") << endl;  // Expected: 6
    
    // Edge case: repeating at start
    cout << "Example 8: " << solution.lengthOfLongestSubstring("aab") << endl;  // Expected: 2
    // "ab"
    
    // Edge case: repeating at end
    cout << "Example 9: " << solution.lengthOfLongestSubstring("abca") << endl;  // Expected: 3
    // "abc" or "bca"
    
    // Edge case: long substring in middle
    cout << "Example 11: " << solution.lengthOfLongestSubstring("aaabcdefgh") << endl;  // Expected: 8
    // "abcdefgh"
    
    // Edge case: with digits
    cout << "Example 12: " << solution.lengthOfLongestSubstring("123451234") << endl;  // Expected: 5
    // "12345"
    
    return 0;
}
