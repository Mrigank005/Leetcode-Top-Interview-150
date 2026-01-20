"""
380. Insert Delete GetRandom O(1)

Time Complexity: O(1) average for all operations
Space Complexity: O(n) where n is number of elements
"""

import random


class RandomizedSet:
    def __init__(self):
        self.values = []
        self.val_to_index = {}

    def insert(self, val: int) -> bool:
        if val in self.val_to_index:
            return False
        self.values.append(val)
        self.val_to_index[val] = len(self.values) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.val_to_index:
            return False
        index_to_remove = self.val_to_index[val]
        last_value = self.values[-1]
        self.values[index_to_remove] = last_value
        self.val_to_index[last_value] = index_to_remove
        self.values.pop()
        del self.val_to_index[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.values)


# Test cases
if __name__ == "__main__":
    # Example 1
    randomizedSet = RandomizedSet()
    print(f"insert(1): {randomizedSet.insert(1)}")  # Expected: True
    print(f"remove(2): {randomizedSet.remove(2)}")  # Expected: False
    print(f"insert(2): {randomizedSet.insert(2)}")  # Expected: True
    print(f"getRandom(): {randomizedSet.getRandom()}")  # Expected: 1 or 2
    print(f"remove(1): {randomizedSet.remove(1)}")  # Expected: True
    print(f"insert(2): {randomizedSet.insert(2)}")  # Expected: False
    print(f"getRandom(): {randomizedSet.getRandom()}")  # Expected: 2
    
    print("\n--- Additional Tests ---")
    randomizedSet2 = RandomizedSet()
    randomizedSet2.insert(10)
    randomizedSet2.insert(20)
    randomizedSet2.insert(30)
    print(f"Set: {randomizedSet2.values}")
    print(f"remove(20): {randomizedSet2.remove(20)}")
    print(f"Set after remove: {randomizedSet2.values}")
    print(f"getRandom(): {randomizedSet2.getRandom()}")
    
    # Test random distribution
    print("\n--- Testing Random Distribution ---")
    randomizedSet3 = RandomizedSet()
    for i in range(1, 6):
        randomizedSet3.insert(i)
    
    counts = {i: 0 for i in range(1, 6)}
    for _ in range(10000):
        counts[randomizedSet3.getRandom()] += 1
    print("Random distribution (10000 calls):", counts)
