/**
 * 1244. Design A Leaderboard
Medium

26

18

Favorite

Share
Design a Leaderboard class, which has 3 functions:

addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
top(K): Return the score sum of the top K players.
reset(playerId): Reset the score of the player with the given id to 0. It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.

 

Example 1:

Input: 
["Leaderboard","addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"]
[[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
Output: 
[null,null,null,null,null,null,73,null,null,null,141]

Explanation: 
Leaderboard leaderboard = new Leaderboard ();
leaderboard.addScore(1,73);   // leaderboard = [[1,73]];
leaderboard.addScore(2,56);   // leaderboard = [[1,73],[2,56]];
leaderboard.addScore(3,39);   // leaderboard = [[1,73],[2,56],[3,39]];
leaderboard.addScore(4,51);   // leaderboard = [[1,73],[2,56],[3,39],[4,51]];
leaderboard.addScore(5,4);    // leaderboard = [[1,73],[2,56],[3,39],[4,51],[5,4]];
leaderboard.top(1);           // returns 73;
leaderboard.reset(1);         // leaderboard = [[2,56],[3,39],[4,51],[5,4]];
leaderboard.reset(2);         // leaderboard = [[3,39],[4,51],[5,4]];
leaderboard.addScore(2,51);   // leaderboard = [[2,51],[3,39],[4,51],[5,4]];
leaderboard.top(3);           // returns 141 = 51 + 51 + 39;
 

Constraints:

1 <= playerId, K <= 10000
It's guaranteed that K is less than or equal to the current number of players.
1 <= score <= 100
There will be at most 1000 function calls.
 */

/**
 * 直接采用了单hash map，排序的方法实现，因为调用量并不大
 * 最优方法应该是再结合sorted set （红黑树）排序的特性来记录
 */


class Leaderboard {
public:
    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        if (scores_.count(playerId)) {
            scores_[playerId] += score;
        } else {
            scores_[playerId] = score;
        }
    }

    int top(int K) {
        std::vector<int> scores;
        scores.reserve(scores_.size());
        for (const auto& p : scores_) {
            scores.emplace_back(p.second);
        }
        std::sort(std::begin(scores), std::end(scores), std::greater<int>());
        return std::accumulate(std::begin(scores), std::begin(scores) + K, 0);
    }

    void reset(int playerId) {
        scores_[playerId] = 0;
    }

    std::unordered_map<int, int> scores_;
};