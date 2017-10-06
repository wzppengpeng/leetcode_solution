/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


 */

/**
 * 首先判断是否是合法字符，然后剔除掉不合法字符后与翻转之后的字符串比对，速度还不错
 */

class Solution {
public:
    bool isPalindrome(string s) {
        string p; p.reserve(s.size());
        for(auto ch : s) {
            if (check(ch)) {
                p.push_back(std::tolower(ch));
            }
        }
        auto tmp = p;
        std::reverse(std::begin(tmp), std::end(tmp));
        return tmp == p;
    }

    inline bool check(char ch) {
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return true;
        else return false;
    }
};