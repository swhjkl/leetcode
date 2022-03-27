/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    struct Node {
        int val;
        int parent_count;
        vector<int> children;
        Node(int v): val(v), parent_count(0) {}
    };
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> nodes(numCourses, nullptr);
        for (int i = 0; i < numCourses; i++) {
            nodes[i] = new Node(i);
        }
        for (auto &p : prerequisites) {
            nodes[p[1]]->children.push_back(p[0]);
            nodes[p[0]]->parent_count++;
        }
        vector<int> result;
        queue<int> q;
        for (size_t i = 0; i < numCourses; i++) {
            if (!nodes[i]->parent_count) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto size = q.size();
            for (size_t j = 0; j < size; j++) {
                result.push_back(q.front());
                for (auto n : nodes[q.front()]->children) {
                    if (!--nodes[n]->parent_count) {
                        q.push(n);
                    }
                }
                q.pop();
            }
        }
        if (result.size() != numCourses) {
            result.clear();
        }
        return result;
    }
};
// @lc code=end

