/**
 * International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have
 */

/**
 * 使用哈希表进行记录即可
 */

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> sets;
        for(auto& w : words) {
            sets.emplace(translate(w));
        }
        return sets.size();
    }

    string translate(const string& str) {
        string res;
        for(auto ch : str) {
            res.append(m_maps[ch - 'a']);
        }
        return res;
    }

    vector<string> m_maps {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};