/**
 * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.size() < 7) return 0;

        vector<int> stats(26);
        for (int i = 0; i < text.size(); ++i)
            ++stats[text[i]-'a'];

        int result = min(stats[0],stats[1]);
        result = min(result,stats['l'-'a']/2);
        result = min(result,stats['o'-'a']/2);
        result = min(result,stats['n'-'a']);

        return result;
    }
};