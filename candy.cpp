/*
135. Candy

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

// Helper function to print candies distribution
void printCandies(vector<int>& ratings) {
    Solution solution;
    int n = ratings.size();
    vector<int> candies(n, 1);
    
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << candies[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Example 1: " << solution.candy(ratings1);
    cout << " (candies: ";
    printCandies(ratings1);
    cout << ")" << endl;  // Expected: 5 (candies: [2,1,2])
    
    // Example 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Example 2: " << solution.candy(ratings2);
    cout << " (candies: ";
    printCandies(ratings2);
    cout << ")" << endl;  // Expected: 4 (candies: [1,2,1])
    
    // Edge case: single child
    vector<int> ratings3 = {1};
    cout << "Example 3: " << solution.candy(ratings3) << endl;  // Expected: 1
    
    // Edge case: all increasing
    vector<int> ratings4 = {1, 2, 3, 4, 5};
    cout << "Example 4: " << solution.candy(ratings4) << endl;  // Expected: 15
    
    // Edge case: all decreasing
    vector<int> ratings5 = {5, 4, 3, 2, 1};
    cout << "Example 5: " << solution.candy(ratings5) << endl;  // Expected: 15
    
    // Edge case: all same
    vector<int> ratings6 = {1, 1, 1, 1};
    cout << "Example 6: " << solution.candy(ratings6) << endl;  // Expected: 4
    
    // Complex case: valley in middle
    vector<int> ratings7 = {1, 2, 3, 2, 1};
    cout << "Example 7: " << solution.candy(ratings7) << endl;  // Expected: 9
    
    // Complex case: peak in middle
    vector<int> ratings8 = {1, 3, 2, 2, 1};
    cout << "Example 8: " << solution.candy(ratings8) << endl;  // Expected: 7
    
    // Complex case from LeetCode
    vector<int> ratings9 = {1, 2, 87, 87, 87, 2, 1};
    cout << "Example 9: " << solution.candy(ratings9) << endl;  // Expected: 13
    
    return 0;
}
