/**
 * Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

 */


/**
 * 其实就是使用哈希表来记录字母出现的次数，并且比较字母出现情况即可
 * 关于记录最小值的过程可以使用索引来避免拷贝
 */

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> license_cnt;
        for(auto ch : licensePlate) {
            if(is_letter(ch)) ++license_cnt[to_lower(ch)];
        }
        size_t min_index = 0, length = 100000;
        for(size_t i = 0; i < words.size(); ++i) {
            auto dict = count_letter(words[i]);
            bool check = true;
            for(auto& p : license_cnt) {
                if(dict.find(p.first) == dict.end() || p.second > dict[p.first]) {
                    check = false;
                    break;
                }
            }
            if(check && words[i].size() < length) {
                min_index = i;
                length = words[i].size();
            }
        }
        return words[min_index];
    }

    inline char to_lower(char C) {
        if(C >= 'A' && C <= 'Z')
            return C + ('a' - 'A');
        return C;
    }

    inline bool is_letter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    unordered_map<char, int> count_letter(const string& s) {
        unordered_map<char, int> dict;
        for(auto ch : s) ++dict[ch];
        return dict;
    }
};