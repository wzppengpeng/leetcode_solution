/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 */

/**
 * 对于某一个阶梯位置，加上该位置的最小值，应当是前一个到这最小或是前前个最小
 * dp[i + 2] = std::min(dp[i] + cost[i], dp[i + 1] + cost[i]);
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.emplace_back(0);
        vector<int> dp(cost.size() + 2, 0);
        for(size_t i = 0; i < cost.size(); ++i) {
            dp[i + 2] = std::min(dp[i] + cost[i], dp[i + 1] + cost[i]);
        }
        return dp.back();
    }
};