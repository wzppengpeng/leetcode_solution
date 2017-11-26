/**
 * Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
 */

/**
 * 使用哈希表来保存对应关系，这里注意存在一对多的情况，所以使用哈希表加集合的混合思路
 */


class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        gen_map(pairs);
        for(size_t i = 0; i < words1.size(); ++i) {
            auto& word1 = words1[i];
            auto& word2 = words2[i];
            if(word1 == word2) continue;
            auto it = m_similarity.find(word1);
            if(it == m_similarity.end()) return false;
            if(it->second.find(word2) == it->second.end()) return false;
        }
        return true;
    }

    unordered_map<string, unordered_set<string> > m_similarity;

    void gen_map(const vector<pair<string, string>>& pairs) {
        for(auto& p : pairs) {
            auto it = m_similarity.find(p.first);
            if(it != m_similarity.end()) {
                it->second.emplace(p.second);
            } else {
                m_similarity.insert({p.first, {p.second}});
            }
            it = m_similarity.find(p.second);
            if(it != m_similarity.end()) {
                it->second.emplace(p.first);
            } else {
                m_similarity.insert({p.second, {p.first}});
            }
        }
    }
};