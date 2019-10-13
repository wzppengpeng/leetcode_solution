/**
 * There are some chips, and the i-th chip is at position chips[i].

You can perform any of the two following types of moves any number of times (possibly zero) on any chip:

Move the i-th chip by 2 units to the left or to the right with a cost of 0.
Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).
 */

/**
 * 相当于是奇数可以以无代价的方式变成其他奇数，偶数也可以以无代价的方式变成任何偶数
 * 奇数偶数之间互相转换有代价1
 * 所以最后的问题就变成了最小奇数和偶数之间的对比
 */

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd_res = 0, even_res = 0;
        for (int chip : chips) {
            if (chip % 2 == 1) {
                ++odd_res;
            } else {
                ++even_res;
            }
        }
        return std::min(odd_res, even_res);
    }
};