/**
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long presse
 */


/**
 * 直接forward，使用一个字母保存当前的old字母，并优先让name的指针往后移
 */

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size() > typed.size()) return false;
        size_t i = 0, j = 0, n = name.size(), t = typed.size();
        char old = 'A';
        while(i < n && j < t) {
            if(name[i] != typed[j]) {
                if(typed[j++] != old) return false;
            } else {
                old = name[i++];
                ++j;
            }
        }
        if(i != n) return false;
        return true;
    }
};