/*
68. Text Justification

Time Complexity: O(n) where n is total number of characters
Space Complexity: O(n) for the result
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        
        while (i < words.size()) {
            vector<string> lineWords;
            int lineLength = 0;
            
            while (i < words.size()) {
                int neededLength = words[i].length() + (lineWords.empty() ? 0 : 1) + lineLength;
                
                if (neededLength <= maxWidth) {
                    lineWords.push_back(words[i]);
                    lineLength += words[i].length() + (lineWords.size() > 1 ? 1 : 0);
                    i++;
                } else {
                    break;
                }
            }
            
            string line;

            if (i == words.size()) {
                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j < lineWords.size() - 1) {
                        line += ' ';
                    }
                }
                line += string(maxWidth - line.length(), ' ');
                result.push_back(line);
            } else if (lineWords.size() == 1) {
                line = lineWords[0] + string(maxWidth - lineWords[0].length(), ' ');
                result.push_back(line);
            } else {
                int totalChars = 0;
                for (const string& word : lineWords) {
                    totalChars += word.length();
                }
                
                int totalSpaces = maxWidth - totalChars;
                int gaps = lineWords.size() - 1;
                
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int j = 0; j < lineWords.size(); j++) {
                    line += lineWords[j];
                    if (j < gaps) {
                        line += string(spacesPerGap, ' ');
                        if (j < extraSpaces) {
                            line += ' ';
                        }
                    }
                }
                
                result.push_back(line);
            }
        }
        
        return result;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = solution.fullJustify(words1, maxWidth1);
    cout << "Example 1:" << endl;
    for (const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    // Expected:
    // "This    is    an"
    // "example  of text"
    // "justification.  "
    
    cout << endl;
    
    // Example 2
    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    vector<string> result2 = solution.fullJustify(words2, maxWidth2);
    cout << "Example 2:" << endl;
    for (const string& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }
    // Expected:
    // "What   must   be"
    // "acknowledgment  "
    // "shall be        "
    
    cout << endl;
    
    // Example 3
    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", 
                             "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    vector<string> result3 = solution.fullJustify(words3, maxWidth3);
    cout << "Example 3:" << endl;
    for (const string& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }
    // Expected:
    // "Science  is  what we"
    // "understand      well"
    // "enough to explain to"
    // "a  computer.  Art is"
    // "everything  else  we"
    // "do                  "
    
    cout << endl;
    
    // Edge case: single word per line
    vector<string> words4 = {"a", "b", "c", "d", "e"};
    int maxWidth4 = 3;
    vector<string> result4 = solution.fullJustify(words4, maxWidth4);
    cout << "Example 4:" << endl;
    for (const string& line : result4) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}
