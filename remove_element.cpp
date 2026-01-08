/*
27. Remove Element

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = solution.removeElement(nums1, val1);
    cout << "Example 1: k = " << k1 << ", nums = ";
    printArray(nums1, k1);  // Expected: k = 2, nums = [2, 2]
    
    // Example 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = solution.removeElement(nums2, val2);
    cout << "Example 2: k = " << k2 << ", nums = ";
    printArray(nums2, k2);  // Expected: k = 5, nums = [0, 1, 3, 0, 4]
    
    // Edge case: empty array
    vector<int> nums3 = {};
    int val3 = 0;
    int k3 = solution.removeElement(nums3, val3);
    cout << "Example 3: k = " << k3 << ", nums = ";
    printArray(nums3, k3);  // Expected: k = 0, nums = []
    
    // Edge case: all elements are val
    vector<int> nums4 = {2, 2, 2, 2};
    int val4 = 2;
    int k4 = solution.removeElement(nums4, val4);
    cout << "Example 4: k = " << k4 << ", nums = ";
    printArray(nums4, k4);  // Expected: k = 0, nums = []
    
    // Edge case: no elements are val
    vector<int> nums5 = {1, 2, 3, 4};
    int val5 = 5;
    int k5 = solution.removeElement(nums5, val5);
    cout << "Example 5: k = " << k5 << ", nums = ";
    printArray(nums5, k5);  // Expected: k = 4, nums = [1, 2, 3, 4]
    
    return 0;
}
