/**
 * Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 */

/**
 * 要尽量多的买，因此当价格抵消小于可最高卖价时应该售出
 */


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int best_buy = INT_MAX, best_sell = 0, max_profit = 0;
        for(auto price : prices) {
            if(price + fee < best_sell) {
                max_profit += (best_sell - best_buy);
                best_buy = INT_MAX;
                best_sell = 0;
            }
            if(price + fee < best_buy) best_buy = price + fee;
            if(price > best_sell && price - best_buy > 0) best_sell = price;
        }
        if(best_sell - best_buy > 0) max_profit += (best_sell - best_buy);
        return max_profit;
    }
};