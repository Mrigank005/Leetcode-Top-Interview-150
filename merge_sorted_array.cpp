/*
88. Merge Sorted Array
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      
        int j = n - 1;      
        int k = m + n - 1; 
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    cout << "Example 1: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;  // Expected: 1 2 2 3 5 6
    
    // Example 2
    nums1 = {1};
    nums2 = {};
    solution.merge(nums1, 1, nums2, 0);
    cout << "Example 2: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;  // Expected: 1
    
    // Example 3
    nums1 = {0};
    nums2 = {1};
    solution.merge(nums1, 0, nums2, 1);
    cout << "Example 3: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;  // Expected: 1
    
    return 0;
}
