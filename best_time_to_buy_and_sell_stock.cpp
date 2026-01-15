/*
121. Best Time to Buy and Sell Stock

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }        
        int minPrice = INT_MAX;
        int maxProfit = 0;    
        for (int price : prices) {
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }        
        return maxProfit;
    }    
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Example 1: " << solution.maxProfit(prices1) << endl;  // Expected: 5
    
    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Example 2: " << solution.maxProfit(prices2) << endl;  // Expected: 0
    
    // Edge case: single price
    vector<int> prices3 = {5};
    cout << "Example 3: " << solution.maxProfit(prices3) << endl;  // Expected: 0
    
    // Edge case: two prices increasing
    vector<int> prices4 = {1, 2};
    cout << "Example 4: " << solution.maxProfit(prices4) << endl;  // Expected: 1
    
    // Edge case: two prices decreasing
    vector<int> prices5 = {2, 1};
    cout << "Example 5: " << solution.maxProfit(prices5) << endl;  // Expected: 0
    
    // Counter-example from explanation
    vector<int> prices6 = {2, 4, 1};
    cout << "Example 6: " << solution.maxProfit(prices6) << endl;  // Expected: 2
    
    // Large profit at end
    vector<int> prices7 = {3, 2, 6, 5, 0, 3};
    cout << "Example 7: " << solution.maxProfit(prices7) << endl;  // Expected: 4 (2->6)
    
    return 0;
}
