/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> hash;

    int dfs(int id) {
        auto p = hash[id];
        int res = p->importance;
        for(auto sub : p->subordinates) {
            res += dfs(sub);
        }
        return res;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(auto e : employees) hash[e->id] = e;
        return dfs(id);        
    }
};