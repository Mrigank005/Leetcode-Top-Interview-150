"""
76. Minimum Window Substring

Time Complexity: O(m + n) where m = len(s), n = len(t)
Space Complexity: O(m + n) for the hashmaps
"""

from collections import Counter, defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t or len(s) < len(t):
            return ""
        
        t_freq = Counter(t)
        required = len(t_freq) 
        window_freq = defaultdict(int)
        formed = 0 
        left = 0
        min_len = float('inf')
        min_left = 0
        
        for right in range(len(s)):
            char = s[right]
            window_freq[char] += 1
            if char in t_freq and window_freq[char] == t_freq[char]:
                formed += 1
            while formed == required and left <= right:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_left = left
                char = s[left]
                window_freq[char] -= 1
                if char in t_freq and window_freq[char] < t_freq[char]:
                    formed -= 1
                
                left += 1
        
        return "" if min_len == float('inf') else s[min_left:min_left + min_len]
 
# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "ADOBECODEBANC"
    t1 = "ABC"
    print(f"Example 1: '{solution.minWindow(s1, t1)}'")  # Expected: "BANC"
    
    # Example 2
    s2 = "a"
    t2 = "a"
    print(f"Example 2: '{solution.minWindow(s2, t2)}'")  # Expected: "a"
    
    # Example 3
    s3 = "a"
    t3 = "aa"
    print(f"Example 3: '{solution.minWindow(s3, t3)}'")  # Expected: ""
    
    # Edge case: t longer than s
    s4 = "ab"
    t4 = "abc"
    print(f"Example 4: '{solution.minWindow(s4, t4)}'")  # Expected: ""
    
    # Edge case: exact match
    s5 = "abc"
    t5 = "abc"
    print(f"Example 5: '{solution.minWindow(s5, t5)}'")  # Expected: "abc"
    
    # Edge case: multiple windows
    s6 = "aaabbbccc"
    t6 = "abc"
    print(f"Example 6: '{solution.minWindow(s6, t6)}'")  # Expected: "abbc" or "bbc"
    
    # Edge case: with duplicates
    s7 = "ADOBECODEBANC"
    t7 = "AABC"
    print(f"Example 7: '{solution.minWindow(s7, t7)}'")  # Expected: "ADOBEC" or "ODEBANC"
    
    # Edge case: t has duplicate characters
    s8 = "aabbcc"
    t8 = "abc"
    print(f"Example 8: '{solution.minWindow(s8, t8)}'")  # Expected: "abbc" or similar
    
    # Edge case: no common characters
    s9 = "abc"
    t9 = "xyz"
    print(f"Example 9: '{solution.minWindow(s9, t9)}'")  # Expected: ""
    
    # Edge case: entire string is minimum
    s10 = "abc"
    t10 = "cba"
    print(f"Example 10: '{solution.minWindow(s10, t10)}'")  # Expected: "abc"