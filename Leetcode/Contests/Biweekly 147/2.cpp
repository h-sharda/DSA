#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:

    set<array<int, 3>> s;
    unordered_map<int, array<int, 2>> m;

    TaskManager(vector<vector<int>>& tasks) {
        s.clear();
        for (const auto &it: tasks) {
            m[it[1]] = {it[2], it[0]};
            s.insert({it[2], it[1], it[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        s.insert({priority, taskId, userId});
        m[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        int p = m[taskId][0], u = m[taskId][1];
        m[taskId][0] = newPriority;
        s.erase({p, taskId, u});
        s.insert({newPriority, taskId, u});
    }
    
    void rmv(int taskId) {
        int p = m[taskId][0], u = m[taskId][1];
        m.erase(taskId);
        s.erase({p, taskId, u});
    }
    
    int execTop() {
        if (s.empty()) return -1;
        int user = (*(--s.end()))[2];
        s.erase(--s.end());
        return user;
    }
};