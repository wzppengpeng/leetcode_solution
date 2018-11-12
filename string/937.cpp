/**
 * You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.


Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 */


/**
 * 利用了string比较自带的字典序
 * stable_sort当左右相等时返回其中一个为true能保留原先的顺序
 */

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::stable_sort(std::begin(logs), std::end(logs),
            [](const string& left, const string& right){
                auto sub_left = left.substr(left.find(' ') + 1);
                auto sub_right = right.substr(right.find(' ') + 1);
                if(std::isdigit(sub_left[0])) return false;
                else if(std::isdigit(sub_right[0])) return true;
                else {
                    return sub_left < sub_right;
                }
            });
        return logs;
    }
};