class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        if (m == 0)
            return true;

        int n = prerequisites[0].size();
        if (n != 2)
            return false;

        vector<vector<int>> adj(numCourses);
        vector<int> dependencies(numCourses, 0);

        for (int i = 0; i < m; i++) {
            int dep = prerequisites[i][0];
            int pre = prerequisites[i][1];
            dependencies[dep]++;
            adj[pre].push_back(dep);
        }

        queue<int> courseQueue;
        for (int j = 0; j < dependencies.size(); j++) {
            if (dependencies[j] == 0)
                courseQueue.push(j);
        }

        while (!courseQueue.empty()) {
            int course = courseQueue.front();
            courseQueue.pop();
            numCourses--;

            for (int neighbours: adj[course]) {
                dependencies[neighbours]--;
                if (dependencies[neighbours] == 0) {
                    courseQueue.push(neighbours);
                }
            }
        }

        if (numCourses == 0)
            return true;
        else
            return false;
        
    }
};
