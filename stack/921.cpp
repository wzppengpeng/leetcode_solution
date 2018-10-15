/**
 * Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.


 */


/**
 * 使用一个数来记录前面的左括号数量，如果前述已经没有左括号，则增加结果数量
 */

class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S.empty()) return 0;
        int num = 0, res = 0;
        for(auto ch : S) {
            if(ch == '(') {
                ++num;
            } else {
                if(num == 0) {
                    ++res;
                } else {
                    --num;
                }
            }
        }
        return res + num;
    }
};