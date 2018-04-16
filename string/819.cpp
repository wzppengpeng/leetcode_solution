/**
 * Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

 */

/**
 * 用两个哈希表，一个记录被禁止的单词
 * 另外一个记录当前单词出现的次数
 */

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banned_set(std::begin(banned), std::end(banned));
        for(auto& ch : paragraph) ch = tolower(ch);
        string word;
        int cnt = 0;
        unordered_map<string, int> word_cnt;
        istringstream ss(paragraph);
        string tmp;
        while(ss >> tmp) {
            if(!judge(tmp.back())) tmp.pop_back();
            if(banned_set.count(tmp)) continue;
            if(++word_cnt[tmp] > cnt) {
                cnt = word_cnt[tmp];
                word = std::move(tmp);
            }
        }
        return word;
    }

    bool judge(char ch) const {
        return ch >= 'a' && ch <= 'z';
    }
};