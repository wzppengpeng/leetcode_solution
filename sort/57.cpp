/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

/**
 * 使用二分查找找到对应的区间位置，然后按照合并方法依次进行合并
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty()) {
            res.emplace_back(std::move(newInterval));
            return res;
        }
        auto loc_iter = std::lower_bound(std::begin(intervals), std::end(intervals), newInterval,
            [](const Interval& left, const Interval& right) {
                if(left.start == right.start) return left.end < right.end;
                return left.start < right.start;
            });
        Interval last; bool has_insert = false;
        auto it = std::begin(intervals);
        if(it == loc_iter) {
            last = newInterval;
            has_insert = true;
        }
        else last = *(it++);
        for(; it != std::end(intervals); ) {
            if(it == loc_iter && !has_insert) {
                if(newInterval.start > last.end) {
                    res.emplace_back(std::move(last));
                    last = newInterval;
                } else {
                    last.end = std::max(last.end, newInterval.end);
                }
                has_insert = true;
            } else {
                if(it->start > last.end) {
                    res.emplace_back(std::move(last));
                    last = *it;
                } else {
                    last.end = std::max(last.end, it->end);
                }
                ++it;
            }
        }
        if(!has_insert) {
            if(newInterval.start > last.end) {
                res.emplace_back(std::move(last));
                last = newInterval;
            } else {
                last.end = std::max(last.end, newInterval.end);
            }
        }
        res.emplace_back(std::move(last));
        return res;
    }
};