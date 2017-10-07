/**
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

/**
 * 反向循环
 * 循环的过程中注意使用贪心算法，只要有收益就加上
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto n = prices.size();
        int res = 0, max = -1;
        for(int i = n - 1; i >= 0; --i) {
            if(max > prices[i]) res += (max - prices[i]);
            max = prices[i];
        }
        return res;
    }
};