/**
 * You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
 */


/**
 * 说了一大堆，其实就是一道使用哈希表来存储树状结构，之后使用dfs进行遍历，添加得分值的过程
 */


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        add_employees(employees);
        return dfs(id);
    }

private:
    unordered_map<int, std::pair<int, vector<int>>> m_employees;

private:
    void add_employees(const vector<Employee*>& employees) {
        for(auto& employee : employees) {
            m_employees.emplace(employee->id, std::make_pair(employee->importance, employee->subordinates));
        }
    }

    int dfs(int id) {
        if(m_employees.find(id) == m_employees.end()) return 0;
        auto it = m_employees.find(id);
        int res = it->second.first;
        if(it->second.second.empty()) return res;
        else {
            for(auto sid : it->second.second) {
                res += (dfs(sid));
            }
            return res;
        }
    }

};