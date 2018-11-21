#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<random>
using namespace std;
const int N = 10;
template<typename T>
void print_vector(string hint, vector<T>& vec) {
  cout << hint << " ";
  for (auto n : vec) {
    cout << n << " ";
  }
  cout << endl;
}
void generate_vector(vector<int>& vec, int size) {
  random_device r;
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(1, 10);
  while (size--) {
    vec.push_back(uniform_dist(e1));
  }
}

int main() {
  // std::partition
  // Reorders the elements in the range [first, last) in such a way 
  // that all elements for which the predicate p returns true 
  // precede the elements for which predicate p returns false.
  // Relative order of the elements is not preserved.
  vector<int> num;
  generate_vector(num, N);
  print_vector("before partition:", num);
  int pivot = 5;
  auto pred = [pivot](const auto& em) {
    return em <= pivot;
  };
  auto it = partition(num.begin(), num.end(), pred);
  print_vector("after partition:", num);
  // std::partition_point
  // Examines the partitioned(as if by std::partition) range[first, last) and locates the end of the first partition, 
  // that is, the first element that does not satisfy p or last if all elements satisfy p.
  cout << "partition_point is: " << *partition_point(num.begin(), num.end(), pred) << endl;

  // std::partition_copy
  // Copies the elements from the range[first, last) to two different ranges depending on the value 
  // returned by the predicate p.The elements that satisfy the predicate p are copied to the range 
  // beginning at d_first_true.The rest of the elements are copied to the range beginning at d_first_false.
  vector<int> smaller_than_pivot(10), larger_than_pivot(10);
  auto end_iters = partition_copy(num.begin(), num.end(), smaller_than_pivot.begin(), larger_than_pivot.begin(), pred);
  cout << "smaller than and equal to " << pivot << ": ";
  for (vector<int>::iterator it = smaller_than_pivot.begin(); it != end_iters.first; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "larger than " << pivot << ": ";
  for (vector<int>::iterator it = larger_than_pivot.begin(); it != end_iters.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}