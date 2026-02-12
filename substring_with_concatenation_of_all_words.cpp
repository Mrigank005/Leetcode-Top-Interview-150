/*
30. Substring with Concatenation of All Words

Time Complexity: O(n * m) where n is length of s, m is number of words
Space Complexity: O(m) for the hashmaps
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        if (totalLen > s.length()) {
            return {};
        }
        
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        vector<int> result;
        
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int right = offset;
            unordered_map<string, int> currentFreq;
            
            while (right + wordLen <= s.length()) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordFreq.find(word) != wordFreq.end()) {
                    currentFreq[word]++;
                    
                    while (currentFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        left += wordLen;
                    }
                    
                    if (right - left == totalLen) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        currentFreq[leftWord]--;
                        left += wordLen;
                    }
                } else {
                    currentFreq.clear();
                    left = right;
                }
            }
        }
        
        return result;
    }
};


// Helper function to print results
void printResult(const vector<int>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<string> words1 = {"foo", "bar"};
    cout << "Example 1: ";
    printResult(solution.findSubstring("barfoothefoobarman", words1));  // Expected: [0,9]
    
    // Example 2
    vector<string> words2 = {"word", "good", "best", "word"};
    cout << "Example 2: ";
    printResult(solution.findSubstring("wordgoodgoodgoodbestword", words2));  // Expected: []
    
    // Example 3
    vector<string> words3 = {"bar", "foo", "the"};
    cout << "Example 3: ";
    printResult(solution.findSubstring("barfoofoobarthefoobarman", words3));  // Expected: [6,9,12]
    
    // Edge case: single word
    vector<string> words4 = {"aa"};
    cout << "Example 4: ";
    printResult(solution.findSubstring("aaa", words4));  // Expected: [0,1]
    
    // Edge case: word appears multiple times
    vector<string> words5 = {"aa", "aa", "aa"};
    cout << "Example 5: ";
    printResult(solution.findSubstring("aaaaaaaa", words5));  // Expected: [0,1,2]
    
    // Edge case: no match
    vector<string> words6 = {"ef", "gh"};
    cout << "Example 6: ";
    printResult(solution.findSubstring("abcd", words6));  // Expected: []
    
    // Edge case: exact match
    vector<string> words7 = {"foo", "bar"};
    cout << "Example 7: ";
    printResult(solution.findSubstring("foobar", words7));  // Expected: [0]

    return 0;
}
