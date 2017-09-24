/**
 * You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 15
Explanation:
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
 */

/**
 * 使用一个数组来保存之前所有的valid结果
 * 数组只有最右边可以作为进栈和出栈
 */


class Solution {
public:
    int calPoints(vector<string>& ops) {
        int total = 0;
        for(auto& op : ops) {
            if(op == "+") {
                add_scores(total);
            } else if(op == "D") {
                double_score(total);
            } else if(op == "C") {
                remove_score(total);
            } else {
                add_one_score(std::stoi(op), total);
            }
        }
        return total;
    }

private:
    vector<int> m_valid_score;

    std::pair<int, int> get_last_two_valid_score() {
        return std::make_pair(m_valid_score[m_valid_score.size() - 2], m_valid_score.back());
    }

    void add_one_score(int s, int& total) {
        total += s;
        // update the last valid
        m_valid_score.emplace_back(s);
    }

    void add_scores(int& total) {
        auto last_scores = get_last_two_valid_score();
        add_one_score(last_scores.first + last_scores.second, total);
    }

    void double_score(int& total) {
        auto last_scores = get_last_two_valid_score();
        add_one_score(last_scores.second * 2, total);
    }

    void remove_score(int& total) {
        auto last_scores = get_last_two_valid_score();
        total -= last_scores.second;
        m_valid_score.pop_back();
    }

};