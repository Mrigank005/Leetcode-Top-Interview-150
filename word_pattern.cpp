/*
290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in 
pattern and a non-empty word in s.

Time Complexity: O(n + m) where n is the length of pattern and m is the length of s
Space Complexity: O(w) where w is the number of unique words
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = splitString(s);
        if (pattern.length() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> pattern_to_word;
        unordered_map<string, char> word_to_pattern;
        
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            string word = words[i];
            
            if (pattern_to_word.find(ch) != pattern_to_word.end()) {
                if (pattern_to_word[ch] != word) {
                    return false;
                }
            } else {
                pattern_to_word[ch] = word;
            }
            
            if (word_to_pattern.find(word) != word_to_pattern.end()) {
                if (word_to_pattern[word] != ch) {
                    return false;
                }
            } else {
                word_to_pattern[word] = ch;
            }
        }
        
        return true;
    }
    
private:
    vector<string> splitString(const string& s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Example 1
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Input: pattern = \"" << pattern1 << "\", s = \"" << s1 << "\"" << endl;
    cout << "Output: " << (solution.wordPattern(pattern1, s1) ? "true" : "false") << endl;  // Expected: true
    cout << endl;
    
    // Example 2
    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Input: pattern = \"" << pattern2 << "\", s = \"" << s2 << "\"" << endl;
    cout << "Output: " << (solution.wordPattern(pattern2, s2) ? "true" : "false") << endl;  // Expected: false
    cout << endl;
    
    // Example 3
    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Input: pattern = \"" << pattern3 << "\", s = \"" << s3 << "\"" << endl;
    cout << "Output: " << (solution.wordPattern(pattern3, s3) ? "true" : "false") << endl;  // Expected: false
    cout << endl;
    
    // Additional test case
    string pattern4 = "abba";
    string s4 = "dog dog dog dog";
    cout << "Input: pattern = \"" << pattern4 << "\", s = \"" << s4 << "\"" << endl;
    cout << "Output: " << (solution.wordPattern(pattern4, s4) ? "true" : "false") << endl;  // Expected: false
    
    return 0;
}
