/**
 * Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 */

/**
 * 就是个排序问题，首先根据start排，一样的话根据end排，然后从第二个开始逐渐进行统计合并，始终保持前面的最后一个区间
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;
        std::sort(std::begin(intervals), std::end(intervals),
            [](const Interval& left, const Interval& right) {
                if(left.start == right.start) return left.end < right.end;
                return left.start < right.start;
            });
        auto last = intervals.front();
        vector<Interval> res; res.reserve(intervals.size());
        for(auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            if(it->start > last.end) {
                res.emplace_back(std::move(last));
                last = *it;
            } else {
                last.end = std::max(last.end, it->end);
            }
        }
        res.emplace_back(std::move(last));
        return res;
    }
};