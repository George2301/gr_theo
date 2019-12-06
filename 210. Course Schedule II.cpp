//https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses);
        vector<int> n_prereqs(numCourses);
        
        for (vector<int>& prereq : prerequisites) {
            neighbors[prereq[1]].push_back(prereq[0]);
            ++n_prereqs[prereq[0]];
        }
        
        std::vector<int> path;
        std::queue<int> to_visit;
        for (int i = 0; i < numCourses; ++i) {
            if (n_prereqs[i] == 0) {
                to_visit.push(i);
                path.push_back(i);
            }
        }
        
        while (!to_visit.empty()) {
            if (path.size() == numCourses) return path;
            int current = to_visit.front();
            to_visit.pop();
            
            vector<int>& current_neighbors = neighbors[current];
            for (int neighbor : current_neighbors) {
                --n_prereqs[neighbor];
                if (n_prereqs[neighbor] == 0) {
                    to_visit.push(neighbor);
                    path.push_back(neighbor);
                }
            }
        }
        
        return {};
    }
};