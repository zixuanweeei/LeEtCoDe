#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include <Node.hpp>

using namespace std;

class Solution {
public:
  Node *cloneGraph(Node *node) {
    // Map original node to its cloned node
    unordered_map<Node *, Node *> visited_map;
    stack<pair<Node *, uint32_t>> node_stack;
    node_stack.emplace(node, 0);
    while (!node_stack.empty()) {
      pair<Node *, uint32_t> &top = node_stack.top();
      if (visited_map.count(top.first) == 0) {
        Node *clone = new Node(top.first->val);
        visited_map[top.first] = clone;
      }
      if (top.second == top.first->neighbors.size() - 1) {
        if (visited_map.count(top.first)) {
          Node *cloned_node = visited_map[top.first];
          for (auto &neighbor : cloned_node->neighbors) {
            neighbor->neighbors.push_back(cloned_node);
          }
        }
        node_stack.pop();
      } else {
        Node *neighbor = top.first->neighbors[top.second++];
        if (visited_map.count(neighbor) == 0) {
          Node *cloned_neighbor = new Node(neighbor->val);
          visited_map[neighbor] = cloned_neighbor;
          node_stack.emplace(neighbor, 0);
        }
      }
    }
    return visited_map[node];
  }
};
