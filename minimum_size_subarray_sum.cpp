/*
209. Minimum Size Subarray Sum

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
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int windowSum = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            windowSum += nums[right];
            while (windowSum >= target) {
                minLength = min(minLength, right - left + 1);
                windowSum -= nums[left];
                left++;
            }
        }
        
        return minLength == INT_MAX ? 0 : minLength;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << "Example 1: " << solution.minSubArrayLen(7, nums1) << endl;  // Expected: 2
    // Subarray [4, 3] has sum 7
    
    // Example 2
    vector<int> nums2 = {1, 4, 4};
    cout << "Example 2: " << solution.minSubArrayLen(4, nums2) << endl;  // Expected: 1
    // Single element [4] has sum 4
    
    // Example 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Example 3: " << solution.minSubArrayLen(11, nums3) << endl;  // Expected: 0
    // Maximum sum is 8, cannot reach 11
    
    // Edge case: single element matching
    vector<int> nums4 = {5};
    cout << "Example 4: " << solution.minSubArrayLen(5, nums4) << endl;  // Expected: 1
    
    // Edge case: entire array needed
    vector<int> nums5 = {1, 2, 3, 4, 5};
    cout << "Example 5: " << solution.minSubArrayLen(15, nums5) << endl;  // Expected: 5
    // Sum = 15
    
    // Edge case: first element is sufficient
    vector<int> nums6 = {5, 1, 1, 1};
    cout << "Example 6: " << solution.minSubArrayLen(3, nums6) << endl;  // Expected: 1
    
    // Edge case: target = 1 (minimum)
    vector<int> nums7 = {1, 2, 3};
    cout << "Example 7: " << solution.minSubArrayLen(1, nums7) << endl;  // Expected: 1
    
    // Edge case: large target, cannot achieve
    vector<int> nums8 = {1, 2, 3, 4, 5};
    cout << "Example 8: " << solution.minSubArrayLen(100, nums8) << endl;  // Expected: 0
    
    // Edge case: consecutive elements
    vector<int> nums9 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Example 9: " << solution.minSubArrayLen(15, nums9) << endl;  // Expected: 5
        
    return 0;
}
