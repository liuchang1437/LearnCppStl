#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <random>
using namespace std;
const int N = 7;

class SomeObj {
  friend ostream& operator<< (ostream& os, const SomeObj& obj);
  friend bool operator> (const SomeObj &a, const SomeObj &b);
  friend bool operator< (const SomeObj &a, const SomeObj &b);
public:
  SomeObj(int a, int b) :first(a), second(b) {}
  //bool operator< (const SomeObj &other) {
  //  return first < other.first;
  //}
  int get_first() const { return first; }
  int get_second() const { return second; }
private:
  int first;
  int second;
};
bool operator>(const SomeObj &a, const SomeObj &b);
bool operator<(const SomeObj &a, const SomeObj &b);
class cmp {
public:
  bool operator()(const SomeObj &l, const SomeObj &r) {
    return l > r;
  }
};
void print_vector(string hint, vector<SomeObj>& vec);
void generate_vector(vector<SomeObj>& vec, int size);

int main() {
  vector<SomeObj> num;
  generate_vector(num, N);
  print_vector("before sort:", num);
  // std::sort
  // Sorts the elements in the range [first, last) in ascending order. 
  // The order of equal elements is not guaranteed to be preserved.
  sort(num.begin(), num.end());
  print_vector("after sort:", num);

  sort(num.begin(), num.end(), cmp());
  print_vector("descending order:", num);

  sort(num.begin(), num.end(), [](const SomeObj &a, const SomeObj &b) {
    return a.get_first()==b.get_first() ?a.get_second()>b.get_second():a.get_first()<b.get_first();
  });
  print_vector("custom compare function:", num);

  // std::partial_sort
  // Rearranges elements such that the range[first, middle) 
  // contains the sorted middle - first smallest elements in the range[first, last).
  // The order of equal elements is not guaranteed to be preserved.
  // The order of the remaining elements in the range[middle, last) is unspecified.
  partial_sort(num.begin(), num.begin() + 3, num.end(), cmp());
  print_vector("partial_sort(3):", num);

  // std::nth_element
  // nth_element is a partial sorting algorithm that rearranges elements in[first, last) such that :
  // The element pointed at by nth is changed to whatever element would occur in that position if[first, last) were sorted.
  // All of the elements before this new nth element are less than or equal to the elements after the new nth element.
  nth_element(num.begin(), num.begin() + 3, num.end());
  print_vector("nth_element(3):", num);

  // std::inplace_merge
  // Merges two consecutive sorted ranges[first, middle) and [middle, last) into one sorted range[first, last).
  // For equivalent elements in the original two ranges, the elements from the first range(preserving their original order) 
  // precede the elements from the second range(preserving their original order).
  inplace_merge(num.begin(), num.begin() + 3, num.end());
  print_vector("inplace_merge:", num);

  // std::stable_sort
  // Sorts the elements in the range[first, last) in ascending order.The order of equivalent elements is guaranteed to be preserved.

  stable_sort(num.begin(), num.end(), cmp());
  print_vector("stable_sort:", num);
  
  return 0;
}

void print_vector(string hint, vector<SomeObj>& vec) {
  cout << hint << " ";
  for (auto n : vec) {
    cout << n << " ";
  }
  cout << endl;
}

ostream& operator<< (ostream& os, const SomeObj& obj) {
  os << "{" << obj.first << ", " << obj.second << "}";
  return os;
}

bool operator>(const SomeObj &a, const SomeObj &b) {
  return a.first > b.first;
}
bool operator<(const SomeObj &a, const SomeObj &b) {
  return a.first < b.first;
}

void generate_vector(vector<SomeObj>& vec, int size) {
  random_device r;
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(1, 10);
  while (size--) {
    vec.push_back(SomeObj(uniform_dist(e1), uniform_dist(e1)));
  }
}