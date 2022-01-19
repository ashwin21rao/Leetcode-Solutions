class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.size();
        int max_len = 0;
        
        stack<int> s;
        
        // initially, the whole substring is valid
        s.push(-1);
        
        for (int i=0; i<n; i++) {
            if (str[i] == '(')
                s.push(i);
            else {
                s.pop();
                
                if (!s.empty())
                    max_len = max(max_len, i - s.top());
                else
                    s.push(i);
            }
        }
        
        return max_len;
    }
};

/*
we maintain a stack which stores:
    - the index after which the substring is valid
    - after this, stores indices of opening brackets

when we encounter a closing bracket, we find the length of the valid substring
ending at this position.
the starting position of this valid substring is one of the following:
    - the index of the most recent unclosed opening bracket before the
      corresponding opening bracket of the current closing bracket (if present).
      ex: (()()()) for current index 6 would be index 0.
    - the index after which the current substring is valid.
      ex: ())()() for current index 6 would be index 2.
    - the length of the valid substring ending at i would hence be i - start_idx.
    
when we encounter a closing bracket:
    - we pop an element from the stack.
    - if the substring is valid, we popped the corresponding open bracket.
      s.top() now stores one of the following:
        - index of previous unclosed opening bracket (if present)
        - else, index after which the current substring is valid.
        - hence the length of the current valid substring ending at i is 
          i - s.top().
    
    - else, we popped the previous index at which the substring became 
      invalid. this index is now i. so, we push i onto the stack.
    
time complexity: O(n)
space complexity: O(n)
*/