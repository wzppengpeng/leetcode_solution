/**
 * Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
 */

class Solution {
public:
    string reverseString(string s) {
        std::reverse(std::begin(s), std::end(s));
        return s;
    }
};