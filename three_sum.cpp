/*
15. 3Sum

Time Complexity: O(n²)
Space Complexity: O(1) excluding output
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > 0) {
                break;
            }
            
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int currentSum = nums[left] + nums[right];
                
                if (currentSum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    left++;
                    right--;
                    
                } else if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};


// Helper function to print results
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    cout << "Example 1: ";
    printResult(solution.threeSum(nums1));
    // Expected: [[-1,-1,2],[-1,0,1]]
    
    // Example 2
    vector<int> nums2 = {0, 1, 1};
    cout << "Example 2: ";
    printResult(solution.threeSum(nums2));
    // Expected: []
    
    // Example 3
    vector<int> nums3 = {0, 0, 0};
    cout << "Example 3: ";
    printResult(solution.threeSum(nums3));
    // Expected: [[0,0,0]]
    
    // Edge case: exactly 3 elements summing to 0
    vector<int> nums4 = {-1, 0, 1};
    cout << "Example 4: ";
    printResult(solution.threeSum(nums4));
    // Expected: [[-1,0,1]]
    
    // Edge case: no triplets
    vector<int> nums5 = {1, 2, 3};
    cout << "Example 5: ";
    printResult(solution.threeSum(nums5));
    // Expected: []
    
    // Edge case: multiple triplets with duplicates
    vector<int> nums6 = {-2, 0, 0, 2, 2};
    cout << "Example 6: ";
    printResult(solution.threeSum(nums6));
    // Expected: [[-2,0,2]]
    
    // Edge case: all negative
    vector<int> nums7 = {-1, -2, -3};
    cout << "Example 7: ";
    printResult(solution.threeSum(nums7));
    // Expected: []
    
    // Edge case: larger array
    vector<int> nums8 = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    cout << "Example 8: ";
    printResult(solution.threeSum(nums8));
    // Expected: [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
    
    // Edge case: with zeros
    vector<int> nums9 = {0, 0, 0, 0};
    cout << "Example 9: ";
    printResult(solution.threeSum(nums9));
    // Expected: [[0,0,0]]
    
    // Edge case: minimum length
    vector<int> nums10 = {1, -1, 0};
    cout << "Example 10: ";
    printResult(solution.threeSum(nums10));
    // Expected: [[-1,0,1]]
    
    return 0;
}
