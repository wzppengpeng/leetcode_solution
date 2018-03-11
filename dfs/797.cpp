/**
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

 */

/**
 * 最基本的dfs问题，由于没有循环，所以可以看成树的思想来求解
 */

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        if(graph.empty()) return res;
        dfs(graph, 0, graph.size() - 1, {}, res);
        return res;
    }

    void dfs(const vector<vector<int> >& g, int i, int total, vector<int> tmp, vector<vector<int>>& res) {
        if(i == total) {
            tmp.emplace_back(total);
            res.emplace_back(std::move(tmp));
            return;
        }
        for(auto& next : g[i]) {
            tmp.emplace_back(i);
            dfs(g, next, total, tmp, res);
            tmp.pop_back();
        }
    }
};