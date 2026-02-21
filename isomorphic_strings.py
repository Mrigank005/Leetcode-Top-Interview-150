"""
205. Isomorphic Strings

Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character, but a character 
may map to itself.

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1) since we have at most 256 ASCII characters
"""

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_to_t = {}
        t_to_s = {}
        
        for char_s, char_t in zip(s, t):
            if char_s in s_to_t:
                if s_to_t[char_s] != char_t:
                    return False
            else:
                s_to_t[char_s] = char_t
            
            if char_t in t_to_s:
                if t_to_s[char_t] != char_s:
                    return False
            else:
                t_to_s[char_t] = char_s
        
        return True


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "egg"
    t1 = "add"
    print(f"Input: s = \"{s1}\", t = \"{t1}\"")
    print(f"Output: {solution.isIsomorphic(s1, t1)}")  # Expected: True
    print()
    
    # Example 2
    s2 = "foo"
    t2 = "bar"
    print(f"Input: s = \"{s2}\", t = \"{t2}\"")
    print(f"Output: {solution.isIsomorphic(s2, t2)}")  # Expected: False
    print()
    
    # Example 3
    s3 = "paper"
    t3 = "title"
    print(f"Input: s = \"{s3}\", t = \"{t3}\"")
    print(f"Output: {solution.isIsomorphic(s3, t3)}")  # Expected: True
    print()
    
    # Additional test case
    s4 = "badc"
    t4 = "baba"
    print(f"Input: s = \"{s4}\", t = \"{t4}\"")
    print(f"Output: {solution.isIsomorphic(s4, t4)}")  # Expected: False
