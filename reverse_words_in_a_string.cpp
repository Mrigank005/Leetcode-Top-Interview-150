/*
151. Reverse Words in a String

Time Complexity: O(n)
Space Complexity: O(n) for the result
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    cout << "Example 1: '" << solution.reverseWords("the sky is blue") << "'" << endl;  // Expected: "blue is sky the"
    
    // Example 2
    cout << "Example 2: '" << solution.reverseWords("  hello world  ") << "'" << endl;  // Expected: "world hello"
    
    // Example 3
    cout << "Example 3: '" << solution.reverseWords("a good   example") << "'" << endl;  // Expected: "example good a"
    
    // Edge case: single word
    cout << "Example 4: '" << solution.reverseWords("hello") << "'" << endl;  // Expected: "hello"
    
    // Edge case: two words
    cout << "Example 5: '" << solution.reverseWords("hello world") << "'" << endl;  // Expected: "world hello"
    
    // Edge case: lots of spaces
    cout << "Example 6: '" << solution.reverseWords("   a   b   c   ") << "'" << endl;  // Expected: "c b a"
      
    return 0;
}
