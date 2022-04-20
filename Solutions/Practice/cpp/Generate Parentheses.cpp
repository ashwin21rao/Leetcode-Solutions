class Solution {
public:
    void generateCombinations(int i, int n, int open_count, int closed_count, 
                              string &combination, vector<string> &out) {
        
        // if combination is done
        if (open_count == n && closed_count == n) {
            out.push_back(combination);
            return;
        }
        
        // add open bracket if possible
        if (open_count < n) {
            combination.push_back('(');
            generateCombinations(i + 1, n, open_count + 1, closed_count, combination, out);
            combination.pop_back();
        }
            
        // add closing bracket if possible
        if (closed_count < open_count) {
            combination.push_back(')');
            generateCombinations(i + 1, n, open_count, closed_count + 1, combination, out);
            combination.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string combination = "";
        vector<string> out;
        
        generateCombinations(0, n, 0, 0, combination, out);
        return out;
    }
};

/*
we use backtracking to enumerate all possibilities.

we keep a count of:
    - the number of opening brackets added so far (open_count).
    - the number of closing brackets added so far (closed_count).

at each position, we have 2 choices:
    - include an opening bracket: 
        - this is possible if open_count < n.
    - include a closing bracket:
        - this is possible if closed_count < open_count.
        - else, the combination will be invalid, since the added
          closing bracket will not have a corresponding opening bracket.

when open_count = closed_count = n, we have finished the combination.

time complexity: O(2n * 2^2n)
space complexity: O(2n)

https://leetcode.com/problems/generate-parentheses/
*/