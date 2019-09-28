/**
 * You are given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.


 */


/**
 * 栈类型问题可以用递归方式解决，在当前状态，如果是'('，优先向下解决子问题
 * 当解决完子问题，出栈上一个阶段，拼接子问题结果
 */

class Solution {
public:
    string reverseParentheses(string s) {
        size_t i = 0;
        return revert(s, i);
    }

    string revert(const string& s, size_t& i) {
        string res;
        while(i < s.size()) {
            if(s[i] == '(') {
                res += revert(s, ++i);
            } else if(s[i] == ')') {
                reverse(begin(res), end(res));
                return res;
            } else {
                res.push_back(s[i]);
            }
            ++i;
        }
        return res;
    }

};