/**
 * Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 */


/**
 * 实际上使用的是memory的思路，使用一个栈将到目前位置之前所有的能连续起来的连续子序列记录下来，也就是对于新输入的数字，在栈顶记录往前最多的连续
 */


class StockSpanner {
public:
    StockSpanner() : st_() {}

    int next(int price) {
        int pre = 1;
        while(!st_.empty() && price >= st_.top().first) {
            pre += st_.top().second;
            st_.pop();
        }
        st_.push(std::make_pair(price, pre));
        return st_.top().second;
    }

private:
    std::stack<std::pair<int, int>> st_;

};