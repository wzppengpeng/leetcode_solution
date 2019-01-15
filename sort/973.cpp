/**
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)


 */

/**
 * 排个序就找出前K小
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compute_dis = [](const vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1];
        };
        std::sort(std::begin(points), std::end(points),
            [compute_dis](const vector<int>& left, const vector<int>& right) {
                return compute_dis(left) < compute_dis(right);
            });
        points.resize(K);
        return points;
    }
};