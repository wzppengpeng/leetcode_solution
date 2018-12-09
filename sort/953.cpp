/**
 * In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.


Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 */


/**
 * 即判断区间是否有序，使用std::is_sorted进行返回
 * 判断两个单词时，将当前字母映射为实际的序号大小进行判断
 */

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<size_t> order_vec(26, 0);
        for(size_t i = 0; i < 26; ++i) {
            order_vec[char_to_loc(order[i])] = i;
        }
        return std::is_sorted(std::begin(words), std::end(words),
            [this, &order_vec](const string& left, const string& right) {
                return lexical_compare(left, right, order_vec);
            });
    }

    bool lexical_compare(const string& left, const string& right, const vector<size_t>& order) {
        size_t i = 0;
        for(; i < left.size() && i < right.size(); ++i) {
            char l = left[i], r = right[i];
            if(order[char_to_loc(l)] < order[char_to_loc(r)])
                return true;
            else if(order[char_to_loc(l)] > order[char_to_loc(r)])
                return false;
        }
        return i == left.size();
    }

    inline size_t char_to_loc(char ch) const {
        return ch - 'a';
    }
};