/**
 * Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"]
 */

/**
 * 并查集使用key-value来表示某一个key对应的组号
 * 首先添加所有的key初始化
 * 之后依次进行union_find,此时一是改变其中一个的组号，另外就是将相同组号的其他相关点全部调整为新的组号，并添加到缓存里
 */


class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        m_id = 0;
        for(auto& p : pairs) insert_two_pair(p);
        for(auto& p : pairs) union_find(p.first, p.second);
        for(size_t i = 0; i < words1.size(); ++i) {
            if(words1[i] == words2[i]) continue;
            if(m_union_map.find(words1[i]) == m_union_map.end() || m_union_map.find(words2[i]) == m_union_map.end()) return false;
            if(m_union_map[words1[i]] != m_union_map[words2[i]]) return false;
        }
        return true;
    }


    // union
    int m_id;
    unordered_map<string, int> m_union_map;
    unordered_map<int, vector<string> > m_record;

    void insert_two_pair(const pair<string, string>& pairs) {
        m_union_map.emplace(pairs.first, m_id);
        m_record.emplace(m_id++, vector<string>(1, pairs.first));
        m_union_map.emplace(pairs.second, m_id);
        m_record.emplace(m_id++, vector<string>(1, pairs.second));
    }

    void union_find(const string& p, const string& q) {
        if(m_union_map[p] == m_union_map[q]) return;
        int pid = m_union_map[p], qid = m_union_map[q];
        for(auto& p_relevant : m_record[pid]) {
            m_union_map[p_relevant] = qid;
            m_record[qid].emplace_back(p_relevant);
        }
    }

};