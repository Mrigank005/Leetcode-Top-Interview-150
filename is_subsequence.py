"""
392. Is Subsequence

Time Complexity: O(n) where n is length of t
Space Complexity: O(1)
"""

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        
        i = 0
        
        for char in t:
            if char == s[i]:
                i += 1
                if i == len(s):
                    return True
        
        return False

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1, t1 = "abc", "ahbgdc"
    print(f"Example 1: {solution.isSubsequence(s1, t1)}")  # Expected: True
    
    # Example 2
    s2, t2 = "axc", "ahbgdc"
    print(f"Example 2: {solution.isSubsequence(s2, t2)}")  # Expected: False
    
    # Edge case: empty s
    s3, t3 = "", "ahbgdc"
    print(f"Example 3: {solution.isSubsequence(s3, t3)}")  # Expected: True
    
    # Edge case: empty t
    s4, t4 = "abc", ""
    print(f"Example 4: {solution.isSubsequence(s4, t4)}")  # Expected: False
    
    # Edge case: both empty
    s5, t5 = "", ""
    print(f"Example 5: {solution.isSubsequence(s5, t5)}")  # Expected: True
    
    # Edge case: s equals t
    s6, t6 = "abc", "abc"
    print(f"Example 6: {solution.isSubsequence(s6, t6)}")  # Expected: True
    
    # Edge case: single character match
    s7, t7 = "b", "abc"
    print(f"Example 7: {solution.isSubsequence(s7, t7)}")  # Expected: True
    
    # Edge case: single character no match
    s8, t8 = "d", "abc"
    print(f"Example 8: {solution.isSubsequence(s8, t8)}")  # Expected: False
