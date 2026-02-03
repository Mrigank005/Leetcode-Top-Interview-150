"""
68. Text Justification

Time Complexity: O(n) where n is total number of characters
Space Complexity: O(n) for the result
"""

from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        i = 0
        
        while i < len(words):
            line_words = []
            line_length = 0
            
            while i < len(words):
                needed_length = len(words[i]) + (1 if line_words else 0) + line_length
                
                if needed_length <= maxWidth:
                    line_words.append(words[i])
                    line_length += len(words[i]) + (1 if len(line_words) > 1 else 0)
                    i += 1
                else:
                    break
            
            if i == len(words):
                line = ' '.join(line_words)
                line += ' ' * (maxWidth - len(line))
                result.append(line)
            elif len(line_words) == 1:
                line = line_words[0] + ' ' * (maxWidth - len(line_words[0]))
                result.append(line)
            else:
                total_chars = sum(len(word) for word in line_words)
                total_spaces = maxWidth - total_chars
                gaps = len(line_words) - 1
                
                spaces_per_gap = total_spaces // gaps
                extra_spaces = total_spaces % gaps
                
                line = ""
                for j, word in enumerate(line_words):
                    line += word
                    if j < gaps:
                        line += ' ' * spaces_per_gap
                        if j < extra_spaces:
                            line += ' '
                
                result.append(line)
        
        return result


# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Example 1
    words1 = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth1 = 16
    result1 = solution.fullJustify(words1, maxWidth1)
    print("Example 1:")
    for line in result1:
        print(f'"{line}"')
    # Expected:
    # "This    is    an"
    # "example  of text"
    # "justification.  "
    
    print()
    
    # Example 2
    words2 = ["What", "must", "be", "acknowledgment", "shall", "be"]
    maxWidth2 = 16
    result2 = solution.fullJustify(words2, maxWidth2)
    print("Example 2:")
    for line in result2:
        print(f'"{line}"')
    # Expected:
    # "What   must   be"
    # "acknowledgment  "
    # "shall be        "
    
    print()
    
    # Example 3
    words3 = ["Science", "is", "what", "we", "understand", "well", "enough", "to", 
              "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
    maxWidth3 = 20
    result3 = solution.fullJustify(words3, maxWidth3)
    print("Example 3:")
    for line in result3:
        print(f'"{line}"')
    # Expected:
    # "Science  is  what we"
    # "understand      well"
    # "enough to explain to"
    # "a  computer.  Art is"
    # "everything  else  we"
    # "do                  "
    
    print()
    
    # Edge case: single word per line
    words4 = ["a", "b", "c", "d", "e"]
    maxWidth4 = 3
    result4 = solution.fullJustify(words4, maxWidth4)
    print("Example 4:")
    for line in result4:
        print(f'"{line}"')
