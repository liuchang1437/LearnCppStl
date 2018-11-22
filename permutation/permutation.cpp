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
  vector<int> num;
  generate_vector(num, N);
  print_vector("init array:", num);
  // std::rotate
  // Performs a left rotation on a range of elements.
  // Specifically, std::rotate swaps the elements in the range [first, last) in such a way
  // that the element n_first becomes the first element of the new range and n_first - 1 
  // becomes the last element.
  rotate(num.begin(), num.begin() + 3, num.end());
  print_vector("rotate 3 steps to left:", num);

  // std::shuffle
  // Reorders the elements in the given range[first, last) such that each possible permutation
  // of those elements has equal probability of appearance.
  random_device rd;
  mt19937 g(rd());
  shuffle(num.begin(), num.end(), g);
  print_vector("shuffle the array:", num);

  // std::next_permutation
  // Transforms the range[first, last) into the next permutation from the set of all permutations 
  // that are lexicographically ordered with respect to operator< or comp.Returns true if such 
  // permutation exists, otherwise transforms the range into the first permutation(as if by 
  // std::sort(first, last)) and returns false
  next_permutation(num.begin(), num.end());
  print_vector("next_permutation:", num);
  next_permutation(num.begin(), num.end());
  print_vector("next_permutation:", num);

  // std::reverse
  // Reverses the order of the elements in the range[first, last)
  reverse(num.begin(), num.end());
  print_vector("reverse:", num);
  return 0;
}