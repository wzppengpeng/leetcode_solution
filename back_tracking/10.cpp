/**
 * Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
 */

/**
 * 优先分析p中下一个字符为*的情况，存在0和多种一起的情况，因此需要考虑直接跳过，单个后移，一起后移三种
 * 注意当p不为空时，s为空也是存在解得的情况的，就是'.*'这种情况
 */

/**
 * 动态规划的解法
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        return core(s, p, 0, 0);
    }

    bool core(const string& s, const string& p, int i, int j) {
        if(i == s.size() && j == p.size()) return true;
        if(i != s.size() && j == p.size()) return false;
        if(j < p.size() - 1 && p[j + 1] == '*') {
            if((i != s.size() && s[i] == p[j]) || (i != s.size() && p[j] == '.')) {
                return core(s, p, i + 1, j + 2) || core(s, p, i + 1, j) || core(s, p, i, j + 2);
            } else {
                return core(s, p, i, j + 2);
            }
        }
        if((i != s.size() && s[i] == p[j]) || (i != s.size() && p[j] == '.'))
            return core(s, p, i + 1, j + 1);
        return false;
    }
};