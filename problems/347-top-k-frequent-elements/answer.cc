#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    heap_.emplace_back(0, 0);
    for (auto v : nums) {
      int idx = -1;
      if (find(v, &idx)) {
        heap_[idx].second += 1;
        swim(idx);
      } else {
        heap_.emplace_back(v, 1);
        num_++;
      }
    }

    vector<int> ret;
    for (int i = 1; i < k + 1 && i < heap_.size(); ++i) ret.push_back(pop());
    return ret;
  }

  void swim(int idx) {
    while (idx > 1 && less(idx / 2, idx)) {
      swap(heap_[idx / 2], heap_[idx]);
      idx /= 2;
    }
  }
  bool find(int key, int *idx) {
    for (int i = 1; i < num_; ++i) {
      if (key == heap_[i].first) {
        *idx = i;
        return true;
      }
    }

    return false;
  }
  bool less(int lhs, int rhs) { return heap_[lhs].second < heap_[rhs].second; }
  int pop() {
    int max = heap_[1].first;
    num_--;
    swap(heap_[1], heap_[num_]);
    sink(1);
    return max;
  }
  void sink(int k) {
    while (2 * k < num_) {
      int j = 2 * k;
      if (j < num_ - 1 && less(j, j + 1)) j++;
      if (!less(k, j)) break;
      swap(heap_[k], heap_[j]);
      k = j;
    }
  }

private:
  vector<pair<int, int>> heap_;
  int num_ = 1;
};

int main(int argv, char **argc) {
  vector<int> nums;
  int k = stoi(argc[1]);
  for (int i = 2; i < argv; ++i) { nums.push_back(stoi(argc[i])); }
  Solution sol;
  auto ret = sol.topKFrequent(nums, k);
  for (auto v : ret) std::cout << v << ", ";
  std::cout << std::endl;

  return 0;
}
