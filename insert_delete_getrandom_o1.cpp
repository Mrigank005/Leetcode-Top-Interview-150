/*
380. Insert Delete GetRandom O(1)

Time Complexity: O(1) average for all operations
Space Complexity: O(n) where n is number of elements
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;


class RandomizedSet {
private:
    vector<int> values;
    unordered_map<int, int> valToIndex;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false;
        }
        int indexToRemove = valToIndex[val];
        int lastValue = values.back();
        values[indexToRemove] = lastValue;
        valToIndex[lastValue] = indexToRemove;
        values.pop_back();
        valToIndex.erase(val);
        return true;
    }
    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};


// Test cases
int main() {
    // Example 1
    RandomizedSet randomizedSet;
    cout << "insert(1): " << (randomizedSet.insert(1) ? "true" : "false") << endl;  // Expected: true
    cout << "remove(2): " << (randomizedSet.remove(2) ? "true" : "false") << endl;  // Expected: false
    cout << "insert(2): " << (randomizedSet.insert(2) ? "true" : "false") << endl;  // Expected: true
    cout << "getRandom(): " << randomizedSet.getRandom() << endl;  // Expected: 1 or 2
    cout << "remove(1): " << (randomizedSet.remove(1) ? "true" : "false") << endl;  // Expected: true
    cout << "insert(2): " << (randomizedSet.insert(2) ? "true" : "false") << endl;  // Expected: false
    cout << "getRandom(): " << randomizedSet.getRandom() << endl;  // Expected: 2
    
    cout << "\n--- Additional Tests ---" << endl;
    RandomizedSet randomizedSet2;
    randomizedSet2.insert(10);
    randomizedSet2.insert(20);
    randomizedSet2.insert(30);
    cout << "remove(20): " << (randomizedSet2.remove(20) ? "true" : "false") << endl;
    cout << "getRandom(): " << randomizedSet2.getRandom() << endl;
    
    // Test multiple operations
    cout << "\n--- Testing Multiple Operations ---" << endl;
    RandomizedSet randomizedSet3;
    for (int i = 1; i <= 5; i++) {
        randomizedSet3.insert(i);
    }
    
    cout << "5 random calls: ";
    for (int i = 0; i < 5; i++) {
        cout << randomizedSet3.getRandom() << " ";
    }
    cout << endl;
    
    return 0;
}
