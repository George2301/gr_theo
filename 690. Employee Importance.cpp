//https://leetcode.com/problems/employee-importance/

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
    void update(vector<int>& a, vector<int>& b, int leader, int weight){
        if(a[leader] == leader){
            b[leader] += weight;
        } else {
            b[leader] += weight;
            update(a, b, a[leader], weight);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        vector<int> a(employees.size(), 0), b(employees.size(), 0);
        unordered_map<int, int> m;
        for(int i = 0; i < a.size(); i++){
            Employee* e = employees[i];
            m[e->id] = i;
            a[i] = i;
            b[i] = e->importance;
        }
        for (int i = 0; i< a.size(); i++){
            Employee* e = employees[i];
            for (auto x : e->subordinates){
                a[m[x]] = i;
            }
        }
        for (int i = 0; i< a.size(); i++){
            Employee* e = employees[i];
            if(a[i] != i){
                update(a, b, a[i], e->importance);
            }
        }
        return b[m[id]];
    }
};