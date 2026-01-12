/*
169. Majority Element

Solution 1: Boyer-Moore Voting Algorithm
Time Complexity: O(n)
Space Complexity: O(1)

Solution 2: HashMap
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
    
    int majorityElementHashMap(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();        
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) {
                return num;
            }
        }        
        return -1;
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {3, 2, 3};
    cout << "Example 1: " << solution.majorityElement(nums1) << endl;  // Expected: 3
    
    // Example 2
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Example 2: " << solution.majorityElement(nums2) << endl;  // Expected: 2
    
    // Edge case: single element
    vector<int> nums3 = {1};
    cout << "Example 3: " << solution.majorityElement(nums3) << endl;  // Expected: 1
    
    // Edge case: all same elements
    vector<int> nums4 = {5, 5, 5, 5, 5};
    cout << "Example 4: " << solution.majorityElement(nums4) << endl;  // Expected: 5
    
    // Test with negative numbers
    vector<int> nums5 = {-1, -1, -1, 2, 2};
    cout << "Example 5: " << solution.majorityElement(nums5) << endl;  // Expected: -1
    
    cout << "\n--- Testing HashMap approach ---" << endl;
    vector<int> nums1_copy = {3, 2, 3};
    vector<int> nums2_copy = {2, 2, 1, 1, 1, 2, 2};
    cout << "Example 1 (HashMap): " << solution.majorityElementHashMap(nums1_copy) << endl;
    cout << "Example 2 (HashMap): " << solution.majorityElementHashMap(nums2_copy) << endl;
    
    return 0;
}
