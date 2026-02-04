/*
125. Valid Palindrome

Time Complexity: O(n)
Space Complexity: O(1) for two-pointer approach, O(n) for filter approach
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: " << (solution.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << endl;  // Expected: true
    
    // Example 2
    cout << "Example 2: " << (solution.isPalindrome("race a car") ? "true" : "false") << endl;  // Expected: false
    
    // Example 3
    cout << "Example 3: " << (solution.isPalindrome(" ") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: empty string
    cout << "Example 4: " << (solution.isPalindrome("") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: single character
    cout << "Example 5: " << (solution.isPalindrome("a") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: all special characters
    cout << "Example 6: " << (solution.isPalindrome(".,!@#") ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: with numbers
    cout << "Example 7: " << (solution.isPalindrome("0P") ? "true" : "false") << endl;  // Expected: false
    
    // Edge case: numbers palindrome
    cout << "Example 8: " << (solution.isPalindrome("1a2b2a1") ? "true" : "false") << endl;  // Expected: true
    
    return 0;
}
