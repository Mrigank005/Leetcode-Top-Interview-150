/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

Time Complexity: O(n * k * log(k)) where n is the number of strings and k is the maximum length of a string
Space Complexity: O(n * k) for storing all strings in the hash map
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;
        
        for (const string& s : strs) {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            anagram_groups[sorted_str].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& pair : anagram_groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

// Helper function to print vector of vector of strings
void printResult(const vector<vector<string>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Input: [\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]" << endl;
    cout << "Output: ";
    printResult(solution.groupAnagrams(strs1));
    cout << endl;
    
    // Test case 2
    vector<string> strs2 = {""};
    cout << "Input: [\"\"]" << endl;
    cout << "Output: ";
    printResult(solution.groupAnagrams(strs2));
    cout << endl;
    
    // Test case 3
    vector<string> strs3 = {"a"};
    cout << "Input: [\"a\"]" << endl;
    cout << "Output: ";
    printResult(solution.groupAnagrams(strs3));
    cout << endl;
    
   
    return 0;
}
