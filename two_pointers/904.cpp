/**
 * In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?



Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.


Note:

1 <= tree.length <= 40000
0 <= tree[i] < tree.length
 */

/**
 * 虽然放在双指针问题下，但是这是一道典型的滑动窗口问题。
 * 用两个loc指示滑动窗口，窗口具有添加和弹出的能力，弹出时指示下一次窗口的起始位置
 * 然后在滑动过程中寻找最大值
 */


class Solution {

    struct FruitWindow {
        pair<int, size_t> a {-1, -1}, b {-1, -1};
        inline bool is_full() const {
            return (a.first >= 0) && (b.first >= 0);
        }

        inline bool is_in_window(int c) const {
            return (a.first == c) || (b.first == c);
        }

        void push(int c, size_t loc) {
            if(a.first == c) a.second = loc;
            else if(b.first == c) b.second = loc;
            else if(a.first == -1) {
                a.first = c;
                a.second = loc;
            } else {
                b.first = c;
                b.second = loc;
            }
        }

        size_t pop() {
            pair<int, size_t>& p = a.second < b.second ? a : b;
            auto r = p.second;
            p.first = -1;
            p.second = -1;
            return r;
        }
    };

public:
    int totalFruit(vector<int>& tree) {
        size_t max_res = 0;
        size_t i = 0, j = 1;
        FruitWindow fw; fw.push(tree[i], i);
        while(j < tree.size()) {
            if(fw.is_full() && !fw.is_in_window(tree[j])) {
                auto new_loc = fw.pop();
                max_res = std::max(max_res, j - i);
                i = new_loc + 1;
            }
            fw.push(tree[j], j);
            ++j;
        }
        max_res = std::max(max_res, j - i);
        return max_res;
    }
};