/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> cloned;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        if (cloned.find(node) == cloned.end()) {
            cloned[node] = new Node(node->val);
            for (auto &neighbor : node->neighbors) {
                cloned[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return cloned[node];
    }
};
// @lc code=end

