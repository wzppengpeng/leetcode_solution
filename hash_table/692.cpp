
/**
 * Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
 */

/**
 * 使用哈希表来记录输入值的位置
 * 使用数组保存输入的计数
 * 最后使用堆排序来处理最前面的结果
 */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, size_t> index;
        vector<std::pair<string, int>> words_cnt;
        words_cnt.reserve(words.size());
        for(auto& str : words) {
            if(index.find(str) != index.end()) {
                words_cnt[index[str]].second += 1;
            } else {
                words_cnt.emplace_back(std::make_pair(str, 1));
                index.emplace(str, words_cnt.size() - 1);
            }
        }
        std::sort(std::begin(words_cnt), std::end(words_cnt),
            [](const std::pair<string, int>& left, const std::pair<string, int>& right) {
                if(left.second > right.second) return true;
                if(left.second == right.second) return left.first < right.first;
                return false;
            });
        vector<string> res; res.reserve(k);
        for(int i = 0; i < k; ++i) {
            res.emplace_back(words_cnt[i].first);
        }
        return res;
    }
};