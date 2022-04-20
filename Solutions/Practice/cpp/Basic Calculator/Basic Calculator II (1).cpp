class Solution {
public:
    int calculate(string str) {
        // operation -> precedence order (BODMAS)
        unordered_map<char, int> precedence = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
        
        // number, operator after it
        stack<pair<int, char>> nums;
        
        int n = str.size();
        int i = 0;
        int cur_num = 0;
        
        while (i < n) {
            // ignore spaces before number
            while (str[i] == ' ')
                i++;
            
            // extract number
            if (isdigit(str[i])) {
                int num = 0;
                while (i < n && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                cur_num = num;
            }
            
            // ignore spaces before operator
            while (str[i] == ' ')
                i++;
            
            // extract operator
            char oper = i < n ? str[i] : '+';
            i++;
            
            // update stack
            while (!nums.empty() && precedence[oper] <= precedence[nums.top().second]) {
                auto &[prev_num, prev_oper] = nums.top();
                
                if (prev_oper == '+')
                    prev_num += cur_num;
                else if (prev_oper == '-')
                    prev_num -= cur_num;
                else if (prev_oper == '*')
                    prev_num *= cur_num;
                else
                    prev_num /= cur_num;
                
                cur_num = prev_num;
                nums.pop();
            }
            nums.push({cur_num, oper});            
        }
        
        return nums.top().first;
    }
};

/*
this solution works for both cases:
    - multiplication and division have the same precedence: assumed in this problem
    - division has a greater precedence than multiplication (BODMAS): assumed in basic calculator 3

- we map each character to its precedence.
- we use a stack which keeps track of previously seen numbers, and the operator immediately 
  after each number.

- at each iteration, we extract the current number and the operator after it.
- while the current operator is of precedence <= the previous operator:
    - perform the previous operation between the previous number and the current number.
    - update the current number to be this result.
    - pop from the stack.
- push the current number and operator onto the stack.

time complexity: O(n)
space complexity: O(n)

https://leetcode.com/problems/basic-calculator-ii/
*/