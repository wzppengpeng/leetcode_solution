/**
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
 */

/**
 * 这个问题首先进行two-point的循环，当遇到不等的情况时，通过指针+-1的方法抛弃掉当前的位置的字符
 */


class Solution {
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size() - 1, true);
    }

    bool validPalindrome(const std::string& s, int begin, int end, bool tol = false) {
        for(; begin < end; ++begin, --end) {
            if(s[begin] != s[end]) {
                if(tol) return validPalindrome(s, begin + 1, end) || validPalindrome(s, begin, end - 1);
                else return false;
            }
        }
        return true;
    }
};