/**
 * Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 */

/**
 * 最快的方法肯定是一遍遍历，遍历是使用一个Bool变量记录是否开头为大写，并用一个计数记住当前的大写数目
 */


class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_num = is_capital(word.front()) ? 1 : 0;
        bool is_first_capital = capital_num == 1;
        for(size_t i = 1; i < word.size(); ++i) {
            if(is_capital(word[i])) {
                if(!is_first_capital || capital_num < i) return false;
                ++capital_num;
            } else {
                if(capital_num > 1) return false;
            }
        }
        return true;
    }

    inline bool is_capital(char ch) {
        return (ch >= 'A') && (ch <= 'Z');
    }
};