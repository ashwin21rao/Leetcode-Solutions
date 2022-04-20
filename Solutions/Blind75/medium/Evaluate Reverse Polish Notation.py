class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        
        for token in tokens:
            # token is an operator
            if token in ["+", "-", "*", "/"]:
                val2 = s.pop()
                val1 = s.pop()
                
                if token == "+":
                    s.append(val1 + val2)
                elif token == "-":
                    s.append(val1 - val2)
                elif token == "*":
                    s.append(val1 * val2)
                else:
                    s.append(int(val1 / val2))            
            
            # token is a number
            else:
                s.append(int(token))
                    
        return s[-1]

"""
use a stack to store all previously seen numbers.

time complexity: O(n)
space complexity: O(n)
"""