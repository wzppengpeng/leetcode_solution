/**
 * Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */


/**
 * 使用栈来保存目前最大的值，遍历到某个数时首先跟栈顶的元素比对，并更新结果
 */


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, size_t>> st;
        for(size_t i = 0; i < temperatures.size(); ++i) {
            while(!st.empty() && temperatures[i] > st.top().first) {
                auto& latest = st.top();
                res[latest.second] = i - latest.second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};