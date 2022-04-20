class Solution:
    def findValue(self, s, i):
        ans = 0
        oper = "+"
        
        while i < len(s) and s[i] != ")":
            # extract operator
            if s[i] in ["-", "+"]:
                oper = "-" if s[i] == "-" else "+"
                i += 1
            
            # recurse
            if s[i] == "(":
                num, i = self.findValue(s, i + 1)
            
            # extract number
            else:
                j = i
                while j < len(s) and s[j].isdigit():
                    j += 1
                num = int(s[i:j])
                i = j
            
            # add to answer
            if oper == "+":
                ans += num
            else:
                ans -= num
        
        return ans, i + 1
        
    def calculate(self, s: str) -> int:
        # remove spaces
        s = "".join(s.split(" "))
        
        ans, _  = self.findValue(s, 0)
        return ans

"""
time complexity: O(n)
space complexity: O(n)
"""