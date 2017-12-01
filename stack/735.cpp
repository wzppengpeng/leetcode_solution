/**
 * We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 */

/**
 * 使用栈来保存往右走的点，当出现往左走的点，依次与栈中的右走点比大小，决定是否出栈，
 * 为了提速，使用deque让复制的时间缩短
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        if(asteroids.empty()) return res;
        res.reserve(asteroids.size());
        deque<int> st; //record the right point
        for(auto point : asteroids) {
            if(point < 0) {
                if(st.empty()) res.emplace_back(point);
                else {
                    while(!st.empty() && st.back() < -1 * point) st.pop_back();
                    if(st.empty()) res.emplace_back(point);
                    else if(st.back() == -1 * point) st.pop_back();
                }
            } else {
                st.push_back(point);
            }
        }
        std::copy(std::begin(st), std::end(st), std::back_inserter(res));
        return res;
    }
};