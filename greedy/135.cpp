/**
 * There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 */

/**
 * 通过两遍贪心，一遍从左到右，第二遍从右到左进行调整
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() < 2) return ratings.size();
        vector<int> cans(ratings.size(), 1);
        for(int i = 1; i < cans.size(); ++i) {
            if(ratings[i] > ratings[i - 1]) cans[i] = cans[i - 1] + 1;
            else cans[i] = 1;
        }
        for(int i = ratings.size() - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1] && cans[i] <= cans[i + 1]) cans[i] = cans[i + 1] + 1;
        }
        return std::accumulate(std::begin(cans), std::end(cans), 0);
    }
};