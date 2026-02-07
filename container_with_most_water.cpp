/*
11. Container With Most Water

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;
            
            maxArea = max(maxArea, currentArea);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Example 1: " << solution.maxArea(height1) << endl;  // Expected: 49
    // Max area between index 1 (height 8) and index 8 (height 7)
    // Area = 7 * min(8, 7) = 7 * 7 = 49
    
    // Example 2
    vector<int> height2 = {1, 1};
    cout << "Example 2: " << solution.maxArea(height2) << endl;  // Expected: 1
    
    // Edge case: two different heights
    vector<int> height3 = {1, 2};
    cout << "Example 3: " << solution.maxArea(height3) << endl;  // Expected: 1
    
    // Edge case: increasing heights
    vector<int> height4 = {1, 2, 3, 4, 5};
    cout << "Example 4: " << solution.maxArea(height4) << endl;  // Expected: 6
    
    // Edge case: decreasing heights
    vector<int> height5 = {5, 4, 3, 2, 1};
    cout << "Example 5: " << solution.maxArea(height5) << endl;  // Expected: 6
    
    // Edge case: all same height
    vector<int> height6 = {3, 3, 3, 3};
    cout << "Example 6: " << solution.maxArea(height6) << endl;  // Expected: 9
    
    // Edge case: tall on edges
    vector<int> height7 = {9, 1, 1, 1, 9};
    cout << "Example 7: " << solution.maxArea(height7) << endl;  // Expected: 36
   
    return 0;
}
