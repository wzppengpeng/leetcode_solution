/**
 * You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.
 */


/**
 * 关键在于使用一个哈希映射表来表示单词到patern的映射，除此之外就是需要使用另外一个表来保证单点映射
 */


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res; res.reserve(words.size());
        unordered_map<char, char> trans;
        unordered_map<char, char> used;
        for(auto& w : words) {
            trans.clear();
            used.clear();
            bool is_ok = true;
            for(size_t i = 0; i < pattern.size(); ++i) {
                if(trans.count(w[i]) && trans[w[i]] != pattern[i]) {
                    is_ok = false;
                    break;
                }
                else if (used.count(pattern[i]) && used[pattern[i]] != w[i]) {
                    is_ok = false;
                    break;
                }
                else if(trans.count(w[i]) == 0) {
                    trans[w[i]] = pattern[i];
                    used[pattern[i]] = w[i];
                }
            }
            if(is_ok) res.emplace_back(w);
        }
        return res;
    }
};