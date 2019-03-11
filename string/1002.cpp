/**
 * Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
 */

/**
 * 将字符串化为数组进行保存
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> char_cnt_res, char_cnt;
        transfer(A[0], char_cnt_res);
        for(size_t i = 1; i < A.size(); ++i) {
            transfer(A[i], char_cnt);
            merge(char_cnt, char_cnt_res);
        }
        vector<string> res;
        for(size_t i = 0; i < 26; ++i) {
            for(int j = 0; j < char_cnt_res[i]; ++j) {
                res.emplace_back(std::string(1, int_to_char(i)));
            }
        }
        return res;
    }

    void transfer(const string& str, vector<int>& char_cnt) {
        char_cnt.resize(26, 0);
        std::fill(std::begin(char_cnt), std::end(char_cnt), 0);
        for(auto ch : str) {
            ++char_cnt[char_to_int(ch)];
        }
    }

    inline int char_to_int(char ch) const {
        return ch - 'a';
    }

    inline char int_to_char(int i) const {
        return 'a' + i;
    }

    void merge(const vector<int>& tmp, vector<int>& char_cnt_res) {
        for(size_t i = 0; i < 26; ++i) {
            char_cnt_res[i] = std::min(char_cnt_res[i], tmp[i]);
        }
    }
};