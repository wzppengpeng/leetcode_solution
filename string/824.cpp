/**
 * A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
 */


/**
 * 遇到这种问题，按逻辑一条一条进行拆分，增强代码可读性
 */


class Solution {
public:
    string toGoatLatin(string S) {
        string res;
        std::istringstream is(S);
        string word;
        size_t idx = 0;
        while(is >> word) {
            res.append(transfer(word));
            res.append(add_post(idx++));
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }

    inline bool is_vovle(char ch) {
        auto tmp = tolower(ch);
        return tmp == 'a' || tmp == 'e' || tmp == 'i'
                || tmp == 'o' || tmp == 'u';
    }

    string transfer(const std::string& word) {
        if(is_vovle(word[0])) {
            return word + "ma";
        } else {
            auto tmp = word.substr(1, word.size() - 1);
            tmp.push_back(word[0]);
            tmp.append("ma");
            return tmp;
        }
    }

    string add_post(size_t idx) {
        return string(idx + 1, 'a');
    }
};