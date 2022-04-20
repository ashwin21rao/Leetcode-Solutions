class Solution {
public:
    int calculate(string str) {
        stack<int> nums;
        
        int n = str.size();
        int i = 0;
        char oper = '+';
        
        while (i < n) {
            // ignore spaces
            if (str[i] == ' ') {
                i++;
                continue;
            }
            
            // extract operator
            if (!isdigit(str[i])) {
                oper = str[i];
                i++;
                continue;
            }
            
            // extract number
            int num = 0;
            while (i < n && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            
            // stack operations
            if (oper == '/')
                nums.top() /= num;
            else if (oper == '*')
                nums.top() *= num;
            else if (oper == '+')
                nums.push(num);
            else
                nums.push(-num);
        }
        
        // add all elements of stack
        int ans = 0;
        while (!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }
        
        return ans;
    }
};

/*
this solution assumes that multiplication and division have the same precedence.

- we use a stack which keeps track of previously seen numbers.
- we keep track of the operator immediately before each number.

- at each iteration, we extract the current operator and the number immediately after it.
- if the current operator is * or /, we perform that operation immediately.
    - we set s.top() to be the result of this operation between the previous and current number.
- if the current operator is + or -, we push +num or -num onto the stack,

- hence, we get rid of all multiplication and division operations.
- all numbers on the stack simply need to be added and subtracted.
- we simply add up all elements in the stack to get the answer 
  (since we pushed -num for subtraction).

time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/basic-calculator-ii/
*/