/*
205. Isomorphic Strings

Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character, but a character 
may map to itself.

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1) since we have at most 256 ASCII characters
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        
        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];
            
            if (s_to_t.find(char_s) != s_to_t.end()) {
                if (s_to_t[char_s] != char_t) {
                    return false;
                }
            } else {
                s_to_t[char_s] = char_t;
            }
            
            if (t_to_s.find(char_t) != t_to_s.end()) {
                if (t_to_s[char_t] != char_s) {
                    return false;
                }
            } else {
                t_to_s[char_t] = char_s;
            }
        }
        
        return true;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Example 1
    string s1 = "egg";
    string t1 = "add";
    cout << "Input: s = \"" << s1 << "\", t = \"" << t1 << "\"" << endl;
    cout << "Output: " << (solution.isIsomorphic(s1, t1) ? "true" : "false") << endl;  // Expected: true
    cout << endl;
    
    // Example 2
    string s2 = "foo";
    string t2 = "bar";
    cout << "Input: s = \"" << s2 << "\", t = \"" << t2 << "\"" << endl;
    cout << "Output: " << (solution.isIsomorphic(s2, t2) ? "true" : "false") << endl;  // Expected: false
    cout << endl;
    
    // Example 3
    string s3 = "paper";
    string t3 = "title";
    cout << "Input: s = \"" << s3 << "\", t = \"" << t3 << "\"" << endl;
    cout << "Output: " << (solution.isIsomorphic(s3, t3) ? "true" : "false") << endl;  // Expected: true
    cout << endl;
    
    // Additional test case
    string s4 = "badc";
    string t4 = "baba";
    cout << "Input: s = \"" << s4 << "\", t = \"" << t4 << "\"" << endl;
    cout << "Output: " << (solution.isIsomorphic(s4, t4) ? "true" : "false") << endl;  // Expected: false
    
    return 0;
}
