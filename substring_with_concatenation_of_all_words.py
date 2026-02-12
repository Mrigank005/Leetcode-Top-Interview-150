"""
30. Substring with Concatenation of All Words

Time Complexity: O(n * m) where n is length of s, m is number of words
Space Complexity: O(m) for the hashmaps
"""

from typing import List
from collections import Counter


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []
        
        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        
        if total_len > len(s):
            return []
        
        word_freq = Counter(words)
        result = []
        
        for offset in range(word_len):
            left = offset
            right = offset
            current_freq = Counter()
            
            while right + word_len <= len(s):
                word = s[right:right + word_len]
                right += word_len
                
                if word in word_freq:
                    current_freq[word] += 1
                    
                    while current_freq[word] > word_freq[word]:
                        left_word = s[left:left + word_len]
                        current_freq[left_word] -= 1
                        left += word_len
                    
                    if right - left == total_len:
                        result.append(left)
                        left_word = s[left:left + word_len]
                        current_freq[left_word] -= 1
                        left += word_len
                else:
                    current_freq.clear()
                    left = right
        
        return result


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    s1 = "barfoothefoobarman"
    words1 = ["foo", "bar"]
    print(f"Example 1: {solution.findSubstring(s1, words1)}")  # Expected: [0, 9]
    
    # Example 2
    s2 = "wordgoodgoodgoodbestword"
    words2 = ["word", "good", "best", "word"]
    print(f"Example 2: {solution.findSubstring(s2, words2)}")  # Expected: []
    
    # Example 3
    s3 = "barfoofoobarthefoobarman"
    words3 = ["bar", "foo", "the"]
    print(f"Example 3: {solution.findSubstring(s3, words3)}")  # Expected: [6, 9, 12]
    
    # Edge case: single word
    s4 = "aaa"
    words4 = ["aa"]
    print(f"Example 4: {solution.findSubstring(s4, words4)}")  # Expected: [0, 1]
    
    # Edge case: word appears multiple times
    s5 = "aaaaaaaa"
    words5 = ["aa", "aa", "aa"]
    print(f"Example 5: {solution.findSubstring(s5, words5)}")  # Expected: [0, 1, 2]
    
    # Edge case: no match
    s6 = "abcd"
    words6 = ["ef", "gh"]
    print(f"Example 6: {solution.findSubstring(s6, words6)}")  # Expected: []
    
    # Edge case: exact match
    s7 = "foobar"
    words7 = ["foo", "bar"]
    print(f"Example 7: {solution.findSubstring(s7, words7)}")  # Expected: [0]
