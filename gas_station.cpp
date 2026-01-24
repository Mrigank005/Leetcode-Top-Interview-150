/*
134. Gas Station

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currentTank = 0;
        int startStation = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            totalTank += gain;
            currentTank += gain;
            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }
        return totalTank >= 0 ? startStation : -1;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Example 1: " << solution.canCompleteCircuit(gas1, cost1) << endl;  // Expected: 3
    
    // Example 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Example 2: " << solution.canCompleteCircuit(gas2, cost2) << endl;  // Expected: -1
    
    // Edge case: single station
    vector<int> gas3 = {5};
    vector<int> cost3 = {4};
    cout << "Example 3: " << solution.canCompleteCircuit(gas3, cost3) << endl;  // Expected: 0
    
    // Edge case: single station (impossible)
    vector<int> gas4 = {2};
    vector<int> cost4 = {3};
    cout << "Example 4: " << solution.canCompleteCircuit(gas4, cost4) << endl;  // Expected: -1
    
    // Edge case: start from last station
    vector<int> gas5 = {3, 1, 1};
    vector<int> cost5 = {1, 2, 2};
    cout << "Example 5: " << solution.canCompleteCircuit(gas5, cost5) << endl;  // Expected: 0
    
    // Edge case: equal gas and cost
    vector<int> gas6 = {5, 5, 5};
    vector<int> cost6 = {5, 5, 5};
    cout << "Example 6: " << solution.canCompleteCircuit(gas6, cost6) << endl;  // Expected: 0
    
    // More complex case
    vector<int> gas7 = {1, 2, 3, 4, 5};
    vector<int> cost7 = {2, 3, 4, 3, 1};
    cout << "Example 7: " << solution.canCompleteCircuit(gas7, cost7) << endl;  // Expected: 4
    
    return 0;
}
