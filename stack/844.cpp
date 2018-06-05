/**
 * Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.


Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
 */

/**
 * 用string来模拟栈，然后进行删除即可
 */

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s_stack, t_stack;
        push_stack(S, &s_stack);
        push_stack(T, &t_stack);
        return s_stack == t_stack;
    }

    void push_stack(const string& S, std::string* s_stack) {
        for(const auto& ch : S) {
            if(ch == '#' && !s_stack->empty()) s_stack->pop_back();
            else if(ch != '#') s_stack->push_back(ch);
        }
    }
};