class FreqStack {
public:
    // freq -> stack of elements with that frequency
    unordered_map<int, stack<int>> elements;
    
    // element -> frequency in stack
    unordered_map<int, int> freq;
    
    // maximum frequency of any element in stack
    int max_freq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        // add element to the stack
        freq[val]++;
        elements[freq[val]].push(val);
        
        max_freq = max(max_freq, freq[val]);
    }
    
    int pop() {
        // pop from stack with highest frequency
        int val = elements[max_freq].top();
        elements[max_freq].pop();
        freq[val]--;
        
        if (elements[max_freq].empty())
            max_freq--;
        
        return val;
    }
};

/*
the maximum frequency stack consists of the following data structures:

1) a hashmap which maps frequency to a stack of all elements with that frequency
   at the time of insertion.
2) a hashmap which maps each element to its frequency in the stack.
3) the maximum frequency of any element in the stack.

for the given example, the frequency stack will look like:
freq        stack             val       freq
  1   ->   5, 7, 4             5          2
  2   ->   5, 7                7          2
  3   ->   5                   4          1

push(val):
    - increment the frequency of val.
    - push val to the stack corresponding to the frequency of val.
    - update the maximum frequency if needed.

pop():
    - pop from the stack corrsponding to the maximum frequency.
    - decrement the frequency of val.
    - update the maximum frequency if needed.

time complexity: O(1) for push and pop
space complexity: O(n) where n is the number of elements inserted

https://leetcode.com/problems/maximum-frequency-stack/
*/