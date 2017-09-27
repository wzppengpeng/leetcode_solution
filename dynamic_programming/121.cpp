/**
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
 */

/**
 * 实际上只需要记录之前的最大值和最低的入手价格即可
 * 每次现根据当前价格和最低价格的差值更新最大利润，然后更新最低价格
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int lowest_price = INT_MAX, max_profit = 0;
        for(auto price : prices) {
            if(lowest_price != INT_MAX) {
                max_profit = max(max_profit, price - lowest_price);
            }
            lowest_price = min(lowest_price, price);
        }
        return max_profit;
    }
};