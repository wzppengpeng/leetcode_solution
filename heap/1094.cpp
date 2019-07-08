/**
 * You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 */


/**
 * 用最小堆（优先级队列）来实现，保证优先拿到当前最先停留的值
 */

class Solution {

private:
    struct PairCMP {
        bool operator() (pair<int, int>& a, pair<int, int>& b) const {
            return a.first > b.first;
        }
    };

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::sort(std::begin(trips), std::end(trips), [](vector<int>& a, vector<int>& b) {
            if(a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[2] < b[2];
            }
        });
        int passenger = 0;
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, PairCMP> pq;
        int i = 0;
        for(const auto& trip : trips) {
            int num = trip[0], start = trip[1], stop = trip[2];
            while(!pq.empty() && start >= pq.top().first) {
                passenger -= pq.top().second;
                pq.pop();
            }
            if(passenger + num > capacity) {
                return false;
            }
            pq.push(std::make_pair(stop, num));
            passenger += num;
        }
        return true;
    }
};