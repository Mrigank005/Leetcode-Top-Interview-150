/*
238. Product of Array Except Self

Time Complexity: O(n)
Space Complexity: O(1) excluding output array
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4};
    cout << "Example 1: ";
    printVector(solution.productExceptSelf(nums1));  // Expected: [24, 12, 8, 6]
    
    // Example 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    cout << "Example 2: ";
    printVector(solution.productExceptSelf(nums2));  // Expected: [0, 0, 9, 0, 0]
    
    // Edge case: two elements
    vector<int> nums3 = {1, 2};
    cout << "Example 3: ";
    printVector(solution.productExceptSelf(nums3));  // Expected: [2, 1]
    
    // Edge case: with negative numbers
    vector<int> nums4 = {-1, -2, -3, -4};
    cout << "Example 4: ";
    printVector(solution.productExceptSelf(nums4));  // Expected: [-24, -12, -8, -6]
    
    // Edge case: multiple zeros
    vector<int> nums5 = {0, 0, 1};
    cout << "Example 5: ";
    printVector(solution.productExceptSelf(nums5));  // Expected: [0, 0, 0]
    
    // Edge case: single zero
    vector<int> nums6 = {1, 0, 3};
    cout << "Example 6: ";
    printVector(solution.productExceptSelf(nums6));  // Expected: [0, 3, 0]
    
    // Edge case: all ones
    vector<int> nums7 = {1, 1, 1, 1};
    cout << "Example 7: ";
    printVector(solution.productExceptSelf(nums7));  // Expected: [1, 1, 1, 1]
    
    return 0;
}
