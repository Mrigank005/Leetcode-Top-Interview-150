/*
167. Two Sum II - Input Array Is Sorted

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            
            if (currentSum == target) {
                return {left + 1, right + 1};
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};


// Test cases
int main() {
    Solution solution;
    
    // Example 1
    vector<int> numbers1 = {2, 7, 11, 15};
    vector<int> result1 = solution.twoSum(numbers1, 9);
    cout << "Example 1: [" << result1[0] << ", " << result1[1] << "]" << endl;  // Expected: [1, 2]
    
    // Example 2
    vector<int> numbers2 = {2, 3, 4};
    vector<int> result2 = solution.twoSum(numbers2, 6);
    cout << "Example 2: [" << result2[0] << ", " << result2[1] << "]" << endl;  // Expected: [1, 3]
    
    // Example 3
    vector<int> numbers3 = {-1, 0};
    vector<int> result3 = solution.twoSum(numbers3, -1);
    cout << "Example 3: [" << result3[0] << ", " << result3[1] << "]" << endl;  // Expected: [1, 2]
    
    // Edge case: two elements
    vector<int> numbers4 = {1, 2};
    vector<int> result4 = solution.twoSum(numbers4, 3);
    cout << "Example 4: [" << result4[0] << ", " << result4[1] << "]" << endl;  // Expected: [1, 2]
    
    // Edge case: negative numbers
    vector<int> numbers5 = {-5, -3, -1, 0, 2, 4};
    vector<int> result5 = solution.twoSum(numbers5, -4);
    cout << "Example 5: [" << result5[0] << ", " << result5[1] << "]" << endl;  // Expected: [1, 3]
    
    // Edge case: duplicates
    vector<int> numbers6 = {1, 2, 3, 3, 4};
    vector<int> result6 = solution.twoSum(numbers6, 6);
    cout << "Example 6: [" << result6[0] << ", " << result6[1] << "]" << endl;  // Expected: [3, 4]
    
    // Edge case: large numbers
    vector<int> numbers7 = {0, 0, 3, 4};
    vector<int> result7 = solution.twoSum(numbers7, 0);
    cout << "Example 7: [" << result7[0] << ", " << result7[1] << "]" << endl;  // Expected: [1, 2]
 
    return 0;
}
