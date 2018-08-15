/**
 * We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.
 */


/**
 * 使用哈希表进行记录
 */


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        auto A_cnt = sentence_to_vec(A);
        auto B_cnt = sentence_to_vec(B);
        vector<string> res;
        for(auto& p : A_cnt) {
            if(p.second == 1 && B_cnt.count(p.first) == 0) {
                res.emplace_back(p.first);
            }
        }
        for(auto& p : B_cnt) {
            if(p.second == 1 && A_cnt.count(p.first) == 0) {
                res.emplace_back(p.first);
            }
        }
        return res;
    }

    unordered_map<string, int> sentence_to_vec(const string& s) {
        std::istringstream ss(s);
        string tmp;
        unordered_map<string, int> str_cnt;
        while(ss >> tmp) {
            ++str_cnt[tmp];
        }
        return str_cnt;
    }
};