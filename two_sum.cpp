/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

Time Complexity: O(n) where n is the length of the array
Space Complexity: O(n) for the hash map
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; 
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Input: nums = ";
    printVector(nums1);
    cout << ", target = " << target1 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums1, target1));
    cout << endl;
    cout << "Explanation: nums[0] + nums[1] = " << nums1[0] << " + " << nums1[1] << " = " << target1 << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    cout << "Input: nums = ";
    printVector(nums2);
    cout << ", target = " << target2 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums2, target2));
    cout << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    cout << "Input: nums = ";
    printVector(nums3);
    cout << ", target = " << target3 << endl;
    cout << "Output: ";
    printVector(solution.twoSum(nums3, target3));
    cout << endl << endl;
    
    return 0;
}
