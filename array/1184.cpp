/**
 * A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.
 */

/**
 * 首先找到数学上较小的起点，那么起点终点将数组化成三段，最小距离就是中间距离和两头距离的较小值
 */

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int real_s = std::min(start, destination), real_d = std::max(start, destination);
        int first_sum = std::accumulate(std::begin(distance), std::begin(distance) + real_s, 0);
        int middle_sum = std::accumulate(std::begin(distance) + real_s, std::begin(distance) + real_d, 0);
        int last_sum = std::accumulate(std::begin(distance) + real_d, std::end(distance), 0);
        return std::min(middle_sum, first_sum + last_sum);
    }
};