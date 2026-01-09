/*
26. Remove Duplicates from Sorted Array

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }        
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


// Helper function to print array
void printArray(const vector<int>& nums, int k) {
    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "]" << endl;
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 1, 2};
    int k1 = solution.removeDuplicates(nums1);
    cout << "Example 1: k = " << k1 << ", nums = ";
    printArray(nums1, k1);  // Expected: k = 2, nums = [1, 2]
    
    // Example 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = solution.removeDuplicates(nums2);
    cout << "Example 2: k = " << k2 << ", nums = ";
    printArray(nums2, k2);  // Expected: k = 5, nums = [0, 1, 2, 3, 4]
    
    // Edge case: single element
    vector<int> nums3 = {1};
    int k3 = solution.removeDuplicates(nums3);
    cout << "Example 3: k = " << k3 << ", nums = ";
    printArray(nums3, k3);  // Expected: k = 1, nums = [1]
    
    // Edge case: all duplicates
    vector<int> nums4 = {1, 1, 1, 1, 1};
    int k4 = solution.removeDuplicates(nums4);
    cout << "Example 4: k = " << k4 << ", nums = ";
    printArray(nums4, k4);  // Expected: k = 1, nums = [1]
    
    // Edge case: no duplicates
    vector<int> nums5 = {1, 2, 3, 4, 5};
    int k5 = solution.removeDuplicates(nums5);
    cout << "Example 5: k = " << k5 << ", nums = ";
    printArray(nums5, k5);  // Expected: k = 5, nums = [1, 2, 3, 4, 5]
    
    return 0;
}
