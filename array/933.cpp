/**
 * Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.

 

Example 1:

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]

 */


/**
 * 使用一个队列保存目前的结果就行
 */

class RecentCounter {
private:
    enum { Interval = 3000 };

public:
    RecentCounter() {}

    int ping(int t) {
        time_que_.push(t);
        while(!time_que_.empty() && time_que_.front() < t - Interval)
            time_que_.pop();
        return time_que_.size();
    }

private:
    std::queue<int> time_que_;
};