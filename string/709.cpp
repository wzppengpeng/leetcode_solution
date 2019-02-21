/**
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.


 */

/**
 * 调用ctring系统函数
 */

class Solution {
public:
    string toLowerCase(string str) {
        for(auto& ch : str) {
            ch = tolower(ch);
        }
        return str;
    }
};