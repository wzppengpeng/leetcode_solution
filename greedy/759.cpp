/**
 * We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

Example 1:
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
 */

/**
 * 该问题应当重点关注时间线上的时间点的worker数量。
 * 因此使用一个有序表来保存时间线上的开始或停止工作的worker数量，
 * 设置初始worker数，然后进行遍历，根据记录的worker数量调整当前时间的总数量，当数量为0时，这中间的时间为休息时间，则添加到结果列表中
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        map<int, int> time_line;
        for(auto& work_schedule : schedule) {
            for(auto& interval : work_schedule) {
                ++time_line[interval.start];
                --time_line[interval.end];
            }
        }
        vector<Interval> res;
        int num_worker = 0;
        for(auto& p : time_line) {
            num_worker += p.second;
            if(num_worker == 0) res.emplace_back(p.first, 0);
            if(num_worker && !res.empty() && res.back().end == 0) res.back().end = p.first;
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};