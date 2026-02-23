/*
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An anagram is a word formed by rearranging the letters of another word, using all 
the original letters exactly once.

Time Complexity: O(n) where n is the length of the strings
Space Complexity: O(k) where k is the number of unique characters (at most 26 for lowercase letters)
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> count_s;
        unordered_map<char, int> count_t;
        
        for (char c : s) {
            count_s[c]++;
        }
        
        for (char c : t) {
            count_t[c]++;
        }
        
        return count_s == count_t;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Example 1
    string s1 = "anagram";
    string t1 = "nagaram";
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: " << (solution.isAnagram(s1, t1) ? "true" : "false") << endl;  // Expected: true
    cout << endl;
    
    // Example 2
    string s2 = "rat";
    string t2 = "car";
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: " << (solution.isAnagram(s2, t2) ? "true" : "false") << endl;  // Expected: false
    cout << endl;
    
    // Additional test cases
    string s3 = "listen";
    string t3 = "silent";
    cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Output: " << (solution.isAnagram(s3, t3) ? "true" : "false") << endl;  // Expected: true
    cout << endl;
    
    string s4 = "hello";
    string t4 = "world";
    cout << "Input: s = \"" << s4 << "\", t = \"" << t4 << "\"" << endl;
    cout << "Output: " << (solution.isAnagram(s4, t4) ? "true" : "false") << endl;  // Expected: false
    
    return 0;
}
