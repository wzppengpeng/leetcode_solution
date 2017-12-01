/**
 * Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.

 */

/**
 * 看似复杂，其实根本不需要建立字典树
 * 首先排序，保证顺序
 * 使用一个哈希集合来保存依次较短的字符串
 * 当当前的字符串大小大于全局结果时，更新结果
 */


class Solution {
public:
    string longestWord(vector<string>& words) {
        std::sort(std::begin(words), std::end(words));
        unordered_set<string> words_set {""};
        string res;
        for(auto& word : words) {
            if(words_set.count(word.substr(0, word.size() - 1))) {
                words_set.emplace(word);
                if(word.size() > res.size()) res = word;
            }
        }
        return res;
    }
};