/*
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed 
by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Time Complexity: O(m + n) where m = len(ransomNote), n = len(magazine)
Space Complexity: O(1) - at most 26 lowercase letters
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineCount;
        for (char c : magazine) {
            magazineCount[c]++;
        }
        for (char c : ransomNote) {
            if (magazineCount[c] <= 0) {
                return false;
            }
            magazineCount[c]--;
        }
        
        return true;
    }
};

// Test cases
void testRansomNote() {
    Solution solution;
    
    // Test case 1: Example 1
    assert(solution.canConstruct("a", "b") == false);
    cout << "Test 1 passed: Different characters" << endl;
    
    // Test case 2: Example 2
    assert(solution.canConstruct("aa", "ab") == false);
    cout << "Test 2 passed: Not enough characters" << endl;
    
    // Test case 3: Example 3
    assert(solution.canConstruct("aa", "aab") == true);
    cout << "Test 3 passed: Enough characters" << endl;
    
    // Test case 4: Empty ransom note
    assert(solution.canConstruct("", "abc") == true);
    cout << "Test 4 passed: Empty ransom note" << endl;
    
    // Test case 5: Single character match
    assert(solution.canConstruct("a", "a") == true);
    cout << "Test 5 passed: Single character match" << endl;
    
    // Test case 6: Ransom note longer than magazine
    assert(solution.canConstruct("abcd", "abc") == false);
    cout << "Test 6 passed: Ransom note longer" << endl;
    
    // Test case 7: All characters used
    assert(solution.canConstruct("abc", "abc") == true);
    cout << "Test 7 passed: All characters used" << endl;
    
    // Test case 8: Multiple of same character
    assert(solution.canConstruct("aaa", "aaaa") == true);
    cout << "Test 8 passed: Multiple same character" << endl;
    
    // Test case 9: Mixed characters
    assert(solution.canConstruct("abc", "aabbcc") == true);
    cout << "Test 9 passed: Mixed characters" << endl;
    
    // Test case 10: Complex case
    assert(solution.canConstruct("hello", "hlleox") == true);
    cout << "Test 10 passed: Complex case - all characters available" << endl;
    
    // Test case 11: Complex case success
    assert(solution.canConstruct("hello", "helloworld") == true);
    cout << "Test 11 passed: Complex case - success" << endl;
    
    // Test case 12: Repeated letters
    assert(solution.canConstruct("aabbcc", "aabbccd") == true);
    cout << "Test 12 passed: Repeated letters" << endl;
    
    cout << "\nAll test cases passed!" << endl;
}

int main() {
    testRansomNote();
    return 0;
}
