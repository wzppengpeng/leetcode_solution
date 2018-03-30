/**
 * 单词level反转字符串
 * 使用两遍翻转即可
 */


class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        std::reverse(std::begin(s), std::end(s));
        size_t i = s.find_first_not_of(' ');
        if(i == string::npos) return;
        size_t j = s.find_first_of(' ', i);
        while(j != string::npos) {
            std::reverse(std::begin(s) + i, std::begin(s) + j);
            i = s.find_first_not_of(' ', j);
            if(i == string::npos) break;
            j = s.find_first_of(' ', i);
        }
        if(i != string::npos) std::reverse(std::begin(s) + i, std::end(s));
    }
};