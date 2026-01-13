/*
189. Rotate Array

Solution 1: Three Reversals (Optimal)
Time Complexity: O(n)
Space Complexity: O(1)

Solution 2: Extra Array
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; 
        reverse(nums, 0, n - 1); 
        reverse(nums, 0, k - 1); 
        reverse(nums, k, n - 1);      
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    
public:
    void rotateExtraArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[(i + k) % n] = nums[i];
        }
        nums = result;
    }
};


// Helper function to print array
void printArray(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums1, 3);
    cout << "Example 1: ";
    printArray(nums1);  // Expected: [5, 6, 7, 1, 2, 3, 4]
    
    // Example 2
    vector<int> nums2 = {-1, -100, 3, 99};
    solution.rotate(nums2, 2);
    cout << "Example 2: ";
    printArray(nums2);  // Expected: [3, 99, -1, -100]
    
    // Edge case: k = 0
    vector<int> nums3 = {1, 2, 3};
    solution.rotate(nums3, 0);
    cout << "Example 3: ";
    printArray(nums3);  // Expected: [1, 2, 3]
    
    // Edge case: k > n
    vector<int> nums4 = {1, 2, 3, 4};
    solution.rotate(nums4, 6);  // 6 % 4 = 2
    cout << "Example 4: ";
    printArray(nums4);  // Expected: [3, 4, 1, 2]
    
    // Edge case: k = n (full rotation)
    vector<int> nums5 = {1, 2, 3};
    solution.rotate(nums5, 3);
    cout << "Example 5: ";
    printArray(nums5);  // Expected: [1, 2, 3]
    
    // Edge case: single element
    vector<int> nums6 = {1};
    solution.rotate(nums6, 5);
    cout << "Example 6: ";
    printArray(nums6);  // Expected: [1]
    
    return 0;
}
