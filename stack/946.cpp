/**
 * Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.


Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 */


/**
 * 剑指offer经典问题，使用一个辅助栈进行判断
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> st;
        size_t j = 0;
        for(size_t i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while(j < popped.size() && !st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};