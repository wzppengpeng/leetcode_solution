/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

/**
 * 需要用到一点动态规划，即保存当前位置向前连续最大位置，注意不是全局最大，而是局部最大
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;
        stack<int> st;
        int i = 0, n = s.size();
        while(i < n && s[i] == ')') ++i;
        if(i == n) return 0;
        st.push(i++);
        int max_len = 0;
        vector<int> dp(n, 0);
        while(i < n) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')' && !st.empty()){
                auto tmp = st.top();
                st.pop();
                int new_len = tmp > 0 ? dp[tmp - 1] + (i - tmp + 1) : (i - tmp + 1);
                dp[i] = new_len;
                max_len = std::max(max_len, new_len);
            }
            ++i;
        }
        return max_len;
    }
};