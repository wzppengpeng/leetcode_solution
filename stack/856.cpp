/**
 * Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 */

/**
 * 用栈来记录分数，退栈的时候优先往栈顶元素里面加分
 */

class Solution {
public:
    int scoreOfParentheses(string S) {
        int total = 0;
        stack<int> st;
        for(auto ch : S) {
            if(ch == '(') {
                st.push(0);
            } else {
                int tmp = st.top() == 0 ? 1 : 2 * st.top();
                st.pop();
                if(st.empty()) total += tmp;
                else st.top() += tmp;
            }
        }
        return total;
    }
};