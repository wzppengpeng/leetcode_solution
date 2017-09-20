/**
 * Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 */


/**
 * 就是一道字典树的题目，整个题目首先应当因地制宜设计一个字典树节点，节点包括当前单词和计数以及下一级的空指针
 * 同时使用哈希表来保存最终的数值以节省时间消耗
 * 在更新的时候针对每一个节点上的值只需要根据当前值和单词最终值之间的差值进行更新，大大降低时间消耗
 */




class MapSum {

struct TrieNode {
std::string word {};
int value;
std::vector<TrieNode*> next_charactor;

TrieNode(const std::string& origin, int ch_idx, int val)
: word(origin), value(val) {
    if(ch_idx >= 0) {
        word.push_back('a' + static_cast<char>(ch_idx));
    }
    next_charactor.resize(26, nullptr);
}

};

public:
    /** Initialize your data structure here. */
    MapSum() : m_head(new TrieNode("", -1, 0))
    {
    }

    void insert(string key, int val) {
        if(key.empty()) return;
        TrieNode* p = m_head;
        for(auto ch : key) {
            int idx = compute_char_index(ch);
            if(p->next_charactor[idx] == nullptr) {
                p->next_charactor[idx] = new TrieNode(p->word,
                    idx, val);
            } else {
                if(m_cnt.find(key) == m_cnt.end()) {
                    p->next_charactor[idx]->value += val;
                } else {
                    p->next_charactor[idx]->value += (val - m_cnt[key]);
                }
            }
            p = p->next_charactor[idx];
        }
        m_cnt[key] = val;
    }

    int sum(string prefix) {
        if(prefix.empty()) return 0;
        TrieNode* p = m_head;
        for(auto ch : prefix) {
            int idx = compute_char_index(ch);
            if(p->next_charactor[idx] == nullptr) return 0;
            p = p->next_charactor[idx];
        }
        return p->value;
    }

private:
    TrieNode* m_head;
    unordered_map<string, int> m_cnt;

private:
    inline int compute_char_index(char ch) { return ch - 'a'; }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */