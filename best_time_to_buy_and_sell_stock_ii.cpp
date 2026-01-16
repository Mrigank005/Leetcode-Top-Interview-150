/*
122. Best Time to Buy and Sell Stock II

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Example 1: " << solution.maxProfit(prices1) << endl;  // Expected: 7
    
    // Example 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Example 2: " << solution.maxProfit(prices2) << endl;  // Expected: 4
    
    // Example 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Example 3: " << solution.maxProfit(prices3) << endl;  // Expected: 0
    
    // Edge case: single price
    vector<int> prices4 = {5};
    cout << "Example 4: " << solution.maxProfit(prices4) << endl;  // Expected: 0
    
    // Edge case: two prices increasing
    vector<int> prices5 = {1, 5};
    cout << "Example 5: " << solution.maxProfit(prices5) << endl;  // Expected: 4
    
    // Edge case: alternating prices
    vector<int> prices6 = {1, 3, 2, 4, 1, 5};
    cout << "Example 6: " << solution.maxProfit(prices6) << endl;  // Expected: 2+2+4 = 8
    
    // All same prices
    vector<int> prices7 = {5, 5, 5, 5};
    cout << "Example 7: " << solution.maxProfit(prices7) << endl;  // Expected: 0
    
    return 0;
}
