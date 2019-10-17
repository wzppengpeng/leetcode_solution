/**
 * 1221. Split a String in Balanced Strings
Easy

52

23

Favorite

Share
Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.



Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
 */


/**
 * 贪婪算法，将问题分段来看，后面的结果并不依赖前面的结果
 * 所以用两个数计数当前最大值，然后得到最终的结果
 */

class Solution {
public:
    int balancedStringSplit(string s) {
        Clear();
        int res = 0;
        for (auto ch : s) {
            if (ch == 'L') {
                ++L_num;
            } else {
                ++R_num;
            }
            if (L_num == R_num) {
                ++res;
                Clear();
            }
        }
        return res;
    }

    int L_num;
    int R_num;

    void Clear() {
        L_num = 0;
        R_num = 0;
    }
};