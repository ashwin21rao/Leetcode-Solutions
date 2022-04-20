class Solution:
    def calculate(self, s: str) -> int:
        nums = []
        oper = "+"
        
        n = len(s)
        i = 0
        while i < n:
            # extract space
            if s[i] == " ":
                i += 1
                continue
            
            # extract operator
            if s[i] in ["+", "-", "*", "/"]:
                oper = s[i]
                i += 1
                continue
                
            # extract number
            j = i
            while j < n and s[j].isdigit():
                j += 1

            num = int(s[i:j])
            i = j
            
            # append to stack
            if oper == "+":
                nums.append(num)
            elif oper == "-":
                nums.append(-num)
            elif oper == "*":
                nums[-1] *= num
            else:
                nums[-1] = int(nums[-1] / num)
        
        # add values in stack
        return sum(nums)

"""
- we maintain a stack of all numbers preceded by a "+" or "-".

- ignore all spaces.
- extract an operator followed by a number.
    - if the operator is '+' or '-', add it
      to the stack (negate if necessary).
    - if the operator is '*' or '/', it takes precedence.
      hence, we multiply or divide the top of the stack
      with this number.
 
- at the end, we have finished all '*' and '/' operations 
  (of higher precedence). we now add up the numbers in the stack.

time complexity: O(n)
space complexity: O(n)
"""