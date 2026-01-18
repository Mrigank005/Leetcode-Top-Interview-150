/*
45. Jump Game II

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }        
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                if (currentEnd >= nums.size() - 1) {
                    break;
                }
            }
        }        
        return jumps;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Example 1: " << solution.jump(nums1) << endl;  // Expected: 2
    
    // Example 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Example 2: " << solution.jump(nums2) << endl;  // Expected: 2
    
    // Edge case: single element
    vector<int> nums3 = {0};
    cout << "Example 3: " << solution.jump(nums3) << endl;  // Expected: 0
    
    // Edge case: two elements
    vector<int> nums4 = {1, 1};
    cout << "Example 4: " << solution.jump(nums4) << endl;  // Expected: 1
    
    // Edge case: can reach end in one jump
    vector<int> nums5 = {5, 1, 1, 1, 1};
    cout << "Example 5: " << solution.jump(nums5) << endl;  // Expected: 1
    
    // Multiple jumps needed
    vector<int> nums6 = {1, 1, 1, 1, 1};
    cout << "Example 6: " << solution.jump(nums6) << endl;  // Expected: 4
    
    // Longer array
    vector<int> nums7 = {1, 2, 3, 4, 1, 1, 1, 1};
    cout << "Example 7: " << solution.jump(nums7) << endl;  // Expected: 3
    
    // Large jumps available
    vector<int> nums8 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    cout << "Example 8: " << solution.jump(nums8) << endl;  // Expected: 2
    
    return 0;
}
