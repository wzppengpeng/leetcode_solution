/**
 * In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.


 */

/**
 * 并查集，依次按照给定的输入顺序进行更新，当发现某一组已经连通时，返回即可
 */

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        build(edges.size());
        for(size_t i = 0; i < edges.size(); ++i) {
            int p = edges[i][0] - 1, q = edges[i][1] - 1;
            if(union_find(p, q)) return edges[i];
        }
        return {};
    }

    vector<int> m_union_points; // index is the point, value is the id
    unordered_map<int, vector<int>> m_record;

    bool union_find(int p, int q) {
        if(m_union_points[p] == m_union_points[q]) return true;
        int pid = m_union_points[p], qid = m_union_points[q];
        for(auto p_relevant : m_record[pid]) {
            m_union_points[p_relevant] = qid;
            m_record[qid].emplace_back(p_relevant);
        }
        return false;
    }

    void build(int s) {
        m_union_points.reserve(s);
        for(int i = 1; i <= s; ++i) {
            m_union_points.emplace_back(i);
            m_record.emplace(i, vector<int>(1, i - 1));
        }
    }
};