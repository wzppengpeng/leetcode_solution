/**
 * We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.
 */


/**
 * 使用一个26顺序的表来表示单词，但是注意B是可以合并的，使用最大的那个数来表示
 */


class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        auto A_cnt = vec_str_to_cnt(A);
        auto B_cnt = vec_str_to_cnt(B);
        vector<int> b_cnt(B_cnt[0]);
        for(size_t j = 0; j < 26; ++j) {
            for(size_t i = 1; i < B_cnt.size(); ++i) {
                b_cnt[j] = std::max(b_cnt[j], B_cnt[i][j]);
            }
        }
        for(size_t i = 0; i < A.size(); ++i) {
            bool is_ok = true;
            auto& a_cnt = A_cnt[i];
            for(size_t j = 0; j < 26; ++j) {
                if(a_cnt[j] < b_cnt[j]) {
                    is_ok = false;
                    break;
                }
            }
            if(is_ok) {
                res.emplace_back(A[i]);
            }
        }
        return res;
    }

    inline int char_to_int(char c) const {
        return c - 'a';
    }

    vector<vector<int>> vec_str_to_cnt(const vector<string>& A) const {
        vector<vector<int>> A_cnt(A.size(), vector<int>(26, 0));
        // transpose A to A_cnt
        for(size_t i = 0; i < A.size(); ++i) {
            for(auto ch : A[i]) {
                ++A_cnt[i][char_to_int(ch)];
            }
        }
        return A_cnt;
    }
};