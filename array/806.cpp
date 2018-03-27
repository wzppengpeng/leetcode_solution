/**
 * We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.

 */

/**
 * 就是遍历，判断边界条件即可
 */

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, now_width = 0;
        for(auto ch : S) {
            auto w = widths[char_to_int(ch)];
            auto tmp_width = now_width + w;
            if(tmp_width > MAX_LEN) {
                ++line;
                now_width = w;
            } else {
                now_width += w;
            }
        }
        return {line, now_width};
    }

    size_t char_to_int(char ch) const {
        return ch - 'a';
    }

    const static int MAX_LEN = 100;
};