/*
42. Trapping Rain Water

Solution 1: Two Pointers 
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } 
            else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Example 1: " << solution.trap(height1) << endl;  // Expected: 6
    
    // Example 2
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    cout << "Example 2: " << solution.trap(height2) << endl;  // Expected: 9
    
    // Edge case: empty
    vector<int> height3 = {};
    cout << "Example 3: " << solution.trap(height3) << endl;  // Expected: 0
    
    // Edge case: single bar
    vector<int> height4 = {5};
    cout << "Example 4: " << solution.trap(height4) << endl;  // Expected: 0
    
    // Edge case: two bars
    vector<int> height5 = {3, 1};
    cout << "Example 5: " << solution.trap(height5) << endl;  // Expected: 0
    
    // Edge case: three bars forming valley
    vector<int> height6 = {3, 0, 2};
    cout << "Example 6: " << solution.trap(height6) << endl;  // Expected: 2
    
    // Edge case: all same height
    vector<int> height7 = {2, 2, 2, 2};
    cout << "Example 7: " << solution.trap(height7) << endl;  // Expected: 0
    
    // Edge case: increasing
    vector<int> height8 = {1, 2, 3, 4};
    cout << "Example 8: " << solution.trap(height8) << endl;  // Expected: 0
    
    // Edge case: decreasing
    vector<int> height9 = {4, 3, 2, 1};
    cout << "Example 9: " << solution.trap(height9) << endl;  // Expected: 0
    
    // Complex case
    vector<int> height10 = {5, 4, 1, 2, 3, 2, 1, 0, 2};
    cout << "Example 10: " << solution.trap(height10) << endl;  // Expected: 6
    
    return 0;
}
