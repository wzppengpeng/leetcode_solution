/**
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job.

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperat
 */


/**
 * 使用二分查找确定当前worker所能工作的最大难度，并且提前将最大难度对应的利润改为当前最大
 */


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> > jobs; jobs.reserve(difficulty.size());
        for(size_t i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        std::sort(std::begin(jobs), std::end(jobs),
            [](const pair<int, int>& left, const pair<int, int>& right) {
                return left.first < right.first;
            });
        int max_pro = 0;
        for(auto& val : jobs) {
            max_pro = std::max(max_pro, val.second);
            val.second = max_pro;
        }
        int res = 0;
        for(auto w : worker) {
            auto it = std::upper_bound(std::begin(jobs), std::end(jobs), w,
                [](int w, const pair<int, int>& val) { return w <  val.first; });
            if(it != std::begin(jobs)) {
                res += (--it)->second;
            }
        }
        return res;
    }
};