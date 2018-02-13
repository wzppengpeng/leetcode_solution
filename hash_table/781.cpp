/**
 * In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

 */

/**
 * 这是一个分组问题，使用哈希表来保存，自己同类数量相同的答案。
 * 然后遍历进行分组， 比如说2的假设有4个，那个分组就是（4/2),把这个结果乘上底数就是最后的答案
 * 注意在保存的过程中首先将其他换成所有的即加一，便于统计
 */

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.empty()) return 0;
        unordered_map<int, double> cnt;
        for(auto an : answers) ++cnt[an + 1];
        int res = 0;
        for(auto& p : cnt) {
            res += (ceil(p.second / p.first) * p.first);
        }
        return res;
    }
};