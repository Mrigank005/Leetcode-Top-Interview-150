/*
274. H-Index

Solution 1: Sort in descending order
Time Complexity: O(n log n)
Space Complexity: O(1) or O(n) depending on sort implementation
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int hIndex = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) {
                hIndex = i + 1;
            } 
            else {
                break;
            }
        }        
        return hIndex;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> citations1 = {3, 0, 6, 1, 5};
    cout << "Example 1: " << solution.hIndex(citations1) << endl;  // Expected: 3
    
    // Example 2
    vector<int> citations2 = {1, 3, 1};
    cout << "Example 2: " << solution.hIndex(citations2) << endl;  // Expected: 1
    
    // Edge case: single paper with 0 citations
    vector<int> citations3 = {0};
    cout << "Example 3: " << solution.hIndex(citations3) << endl;  // Expected: 0
    
    // Edge case: single paper with high citations
    vector<int> citations4 = {100};
    cout << "Example 4: " << solution.hIndex(citations4) << endl;  // Expected: 1
    
    // Edge case: all zeros
    vector<int> citations5 = {0, 0, 0};
    cout << "Example 5: " << solution.hIndex(citations5) << endl;  // Expected: 0
    
    // Edge case: all high citations
    vector<int> citations6 = {10, 10, 10, 10};
    cout << "Example 6: " << solution.hIndex(citations6) << endl;  // Expected: 4
    
    // More complex case
    vector<int> citations7 = {100, 99, 98, 3, 2, 1};
    cout << "Example 7: " << solution.hIndex(citations7) << endl;  // Expected: 3

    return 0;
}