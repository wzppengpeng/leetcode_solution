/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

/**
 * 全等是满足条件的，如果有字母不同则不满足，因此可以通过拆解为无状态的小问题进行迭代
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        auto len = s1.size();
        int cnt[26] = {0};
        for(size_t i = 0; i < len; ++i) {
            ++cnt[char_to_int(s1[i])];
            --cnt[char_to_int(s2[i])];
        }
        if(!check_all_zero(cnt)) return false;
        //recursive
        for(size_t i = 1; i < len; ++i) {
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                || (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))) {
                return true;
            }
        }
        return false;
    }

    int char_to_int(char ch) const {
        return ch - 'a';
    }

    bool check_all_zero(const int* arr) const {
        for(int i = 0; i < 26; ++i) {
            if(arr[i] != 0) return false;
        }
        return true;
    }
};