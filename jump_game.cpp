/*
55. Jump Game

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Example 1: " << (solution.canJump(nums1) ? "true" : "false") << endl;  // Expected: true
    
    // Example 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Example 2: " << (solution.canJump(nums2) ? "true" : "false") << endl;  // Expected: false
    
    // Edge case: single element
    vector<int> nums3 = {0};
    cout << "Example 3: " << (solution.canJump(nums3) ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: can't move from start
    vector<int> nums4 = {0, 1};
    cout << "Example 4: " << (solution.canJump(nums4) ? "true" : "false") << endl;  // Expected: false
    
    // Edge case: large jump at start
    vector<int> nums5 = {5, 1, 1, 1, 1};
    cout << "Example 5: " << (solution.canJump(nums5) ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: zeros in middle but reachable
    vector<int> nums6 = {2, 0, 0};
    cout << "Example 6: " << (solution.canJump(nums6) ? "true" : "false") << endl;  // Expected: true
    
    // Edge case: multiple paths
    vector<int> nums7 = {2, 5, 0, 0};
    cout << "Example 7: " << (solution.canJump(nums7) ? "true" : "false") << endl;  // Expected: true
    
    return 0;
}
