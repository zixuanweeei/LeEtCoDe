#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include <Node.hpp>

using namespace std;

class Solution {
public:
  unordered_map<Node *, Node *> visited_map;
  Node *cloneGraph(Node *node) {
    if (node == nullptr) return node;

    if (visited_map.count(node)) return visited_map[node];

    Node *clone = new Node(node->val);
    visited_map[node] = clone;
    for (auto &neighbor : node->neighbors) {
      clone->neighbors.push_back(cloneGraph(neighbor));
    }

    return clone;
  }
};
