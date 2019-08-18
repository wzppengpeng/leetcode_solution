/**
 * 1160. Find Words That Can Be Formed by Characters
Easy

13

3

Favorite

Share
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.


 */


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        char_vec.resize(26, 0);
        for(auto ch : chars) {
            char_vec[char_index(ch)] += 1;
        }
        int res = 0;
        for(const auto& str : words) {
            auto tmp = char_vec;
            bool flag = true;
            for(auto ch : str) {
                if(tmp[char_index(ch)] == 0) {
                    flag = false;
                    break;
                }
                --tmp[char_index(ch)];
            }
            if(flag) {
                res += str.size();
            }
        }
        return res;
    }

    inline int char_index(char ch) const {
        return ch - 'a';
    }

    vector<int> char_vec;
};
