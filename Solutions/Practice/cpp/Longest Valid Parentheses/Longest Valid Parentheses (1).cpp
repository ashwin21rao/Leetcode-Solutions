class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.size();
        int max_len = 0;
        
        // stores starting indices (indices of open brackets)
        stack<int> s;
        
        // end index of valid substring -> length of substring
        unordered_map<int, int> lengths;
        
        for (int i=0; i<n; i++) {
            if (str[i] == '(')
                s.push(i);
            
            // invalid subtring
            else if (s.empty())
                lengths.clear();
            
            // valid substring found
            else {
                int start_idx = s.top();
                s.pop();

                // length of valid substring
                int length = i - start_idx + 1;
                
                // join previous valid substring behind current one
                if (lengths.find(start_idx - 1) != lengths.end()) {
                    length += lengths[start_idx - 1];
                    lengths.erase(start_idx - 1);
                }
                
                // add length of valid substring to map
                lengths[i] = length;
                max_len = max(max_len, length);
                
                // erase valid substring contained within current one
                // since it is smaller and no longer needed
                if (lengths.find(i - 1) != lengths.end())
                    lengths.erase(i - 1);
            }
        }
        
        return max_len;
    }
};

/*
we store indices of open brackets in a stack to keep track of the length
of the current substring and its validity.

- we also maintain an hashmap which maps the end index of a valid
  substring to its length.
- the hashmap stores all valid subtrings seen so far.
    
when we encounter a valid substring (str[i] = ')'):
    - we find its length as i - s.top() + 1.
    - we use the hashmap to join it to a valid substring immedidiately 
      before it, if present, hence increasing its length.
    - we add the (possibly joined) substring to the hashmap.
    - the valid substring (if any) inside the current valid substring 
      is no longer required and can be removed.  
    - if the substring is invalid, we clear the hashmap.
    
time complexity: O(n)
space complexity: O(n)
*/