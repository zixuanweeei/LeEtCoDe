#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> &vec) {
  std::cout << "[";
  for (size_t i = 0; i < vec.size() - 1; ++i) std::cout << vec[i] << ", ";
  std::cout << vec.back() << "]\n";
}
