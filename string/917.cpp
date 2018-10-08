/**
 * Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.



Example 1:

Input: "ab-cd"
Output: "dc-ba"
 */

/**
 * 使用双指针进行位置控制交换
 */


class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.size() < 2) return S;
        string res(S);
        int i = 0, j = S.size() - 1;
        while(i < S.size() && j >= 0) {
            while(i < S.size() && !(judge(S[i]))) ++i;
            while(j >= 0 && !(judge(res[j]))) --j;
            if(i < S.size() && j >= 0)
                res[j--] = S[i ++];
        }
        return res;
    }

    inline bool judge(char c) const {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};